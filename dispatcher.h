#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include <memory>
#include <thread>
#include <vector>

typedef bool (*Trigger)(void* context);
typedef void (*Action)(void* context);

class Dispatcher {
    struct TrigActPair {
        Trigger trigger;
        Action action;
        void* trigger_context;
        void* action_context;

        std::thread* thread;

        TrigActPair(Trigger t, Action a, void* tc, void* ac);
        ~TrigActPair();
    };

    std::vector<TrigActPair> pairs;

   public:
    int registerCallback(Trigger t,
                         Action a,
                         void* tc = nullptr,
                         void* ac = nullptr);

    int cancelCallback(Trigger t);

    void update();
};

#endif
