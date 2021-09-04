
#include <utility>

class GameCtrl {
    static std::pair<int, int> window_dim;
    static std::pair<int, int> screen_dim;

    static int ui_size;


   public:
    static void init();

    static void openInventory();
    static void rightClick();
    static void leftClick();

    static void select(int x, int y);
}