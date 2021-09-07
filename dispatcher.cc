#include "dispatcher.h"

#include <algorithm>

int Dispatcher::registerAction(Action& action) {
    action._id = _id_max;
    actions.push_back(action);
    _id_max++;
    return _id_max - 1;
}

int Dispatcher::cancelAction(Action& target) {
    std::remove_if(actions.begin(), actions.end(), [&target](auto& action) {
        return target._id == action._id;
    });
    return 0;
}

void Dispatcher::update() {
    for (auto& action : actions) {
        if (action->condition()) {
            action->thread = std::thread(Action::operation, action);
        }
    }
}
