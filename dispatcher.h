#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include <vector>
#include <thread>

typedef bool (*Trigger)(void* context);
typedef void (*Action)(void* context);

class Dispatcher {
    std::vector<Trigger> triggers;
    std::vector<Action> actions;
    std::vector<std::thread> threads;

   public:
    Dispatcher();

    int registerCallback(Trigger t, void* tc, Action a, void* ac, bool threaded = true);

    int cancelCallback(Trigger t);

    void update();
};

#endif
