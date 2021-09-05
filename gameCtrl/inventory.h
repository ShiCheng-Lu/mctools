#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <vector>

class Item;

class Inventory {
    const int size_x;
    const int size_y;

    const float offset_x;
    const float offset_y;

    std::vector<std::vector<Item>> content;

   public:
    void takeItem(int x, int y, bool quick = true);
    void dropItem(int x, int y, bool all = true);

    void takeAll();
    void dropAll();
};

class Chest : public Inventory {
    const int size_x = 9;
    const int size_y = 3;

    const float offset_x = -3;
    const float offset_y = -4;
};

class DoubleChest : public Inventory {};

#endif
