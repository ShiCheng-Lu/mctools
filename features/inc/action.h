#ifndef _ACTION_H_
#define _ACTION_H_

#include <thread>

struct Action {
    std::thread thread;
    bool active;
    int _id;
    virtual bool condition() { return false; }
    virtual void operation() {}
};

#endif
