#include "action.h"
#include "mcWindow.h"
#include "strListener.h"

class VillagerTrader : public Action {
    McWindow& win;
    StrListener& listener;
    bool running;

    void checkTrade();
    void waitForJob();

   public:
    VillagerTrader(McWindow& screen, StrListener& listener)
        : win{screen}, listener{listener} {}

    void addTarget();

    bool condition() override;
    void operation() override;
};
