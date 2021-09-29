#ifndef _INFINIFLY_H_
#define _INFINIFLY_H_

#include "action.h"
#include "strListener.h"

class InfiniFly : public Action {
    StrListener& strListener;
    bool flying = false;
    void fly();

   public:
    InfiniFly(StrListener& strListener) : strListener{strListener} {}

    bool condition() override;
    void operation() override;
};

#endif