#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include <vector>
#include "action.h"

class Dispatcher {
    std::vector<Action*> actions;
    int _id_max;

   public:
    int registerAction(Action* a);

    int cancelAction(Action* a);

    int cancelAction(int trigger_id);

    void update();
};

#endif
