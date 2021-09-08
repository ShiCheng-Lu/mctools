#ifndef _STEAL_H_
#define _STEAL_H_

#include "../gameCtrl/mcWindow.h"
#include "../utils/coord.h"
#include "action.h"

class Steal : public Action {
    McWindow& win;
    int type = 0;

    void takeAll(const Point& inv_size, const Point& offset);

   public:
    Steal(McWindow& screen) : win{screen}, type{0} {}

    bool condition() override;
    void operation() override;
};

#endif
