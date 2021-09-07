#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include <memory>
#include <thread>
#include <vector>

struct Trigger {
    virtual bool operator()() { return false; }
};

struct Action {
    virtual void operator()() {}
};

class Dispatcher {
    struct TrigActPair {
        Trigger* trigger;
        Action* action;

        std::thread* thread;

        TrigActPair(Trigger* t, Action* a);
        ~TrigActPair();
    };

    std::vector<TrigActPair> pairs;

   public:
    int registerCallback(Trigger* t, Action* a);

    int cancelCallback(Trigger* t);

    int cancelCallback(int trigger_id);

    void update();
};

#endif
