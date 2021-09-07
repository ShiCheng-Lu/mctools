#include "dispatcher.h"

#include <algorithm>

Dispatcher::TrigActPair::TrigActPair(Trigger t, Action a, void* tc, void* ac)
    : trigger{t},
      action{a},
      trigger_context{tc},
      action_context{ac},
      thread{nullptr} {}

Dispatcher::TrigActPair::~TrigActPair() {
    thread->join();
}

int Dispatcher::registerCallback(Trigger t, Action a, void* tc, void* ac) {
    pairs.emplace_back(t, a, tc, ac);
    return 0;
}

int Dispatcher::cancelCallback(Trigger t) {
    std::remove_if(pairs.begin(), pairs.end(),
                   [t](auto& p) { return p.trigger == t; });
    return 0;
}

void Dispatcher::update() {
    for (auto& p : pairs) {
        if (p.trigger(p.trigger_context)) {
            p.thread = new std::thread(p.action, p.action_context);
        }
    }
}
