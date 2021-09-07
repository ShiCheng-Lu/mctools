#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include <thread>
#include <vector>

struct Action {
    std::thread thread;
    bool active;
    int _id;
    virtual bool condition() { return false; }
    virtual void operation() {}
};

class Dispatcher {
    std::vector<Action&> actions;
    int _id_max;

   public:
    int registerAction(Action& a);

    int cancelAction(Action& a);

    int cancelAction(int trigger_id);

    void update();
};

#endif
