#include "dispatcher.h"

#include <algorithm>

Dispatcher::TrigActPair::TrigActPair(Trigger* t, Action* a)
    : trigger{t}, action{a}, thread{nullptr} {}

Dispatcher::TrigActPair::~TrigActPair() {
    if (thread) {
        thread->join();
    }
}

int Dispatcher::registerCallback(Trigger* t, Action* a) {
    pairs.emplace_back(t, a);
    return 0;
}

int Dispatcher::cancelCallback(Trigger* t) {
    std::remove_if(pairs.begin(), pairs.end(),
                   [t](auto& p) { return p.trigger == t; });
    return 0;
}

void Dispatcher::update() {
    for (auto& p : pairs) {
        if (p.trigger->operator()()) {
            p.thread = new std::thread(Action::operator(), p.action);
        }
    }
}
