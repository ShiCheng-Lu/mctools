#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <vector>

// class Item;

class Inventory {
   protected:
    const int size_x;
    const int size_y;

    const float offset_x;
    const float offset_y;

    // std::vector<std::vector<Item>> content;

   public:
    Inventory(int size_x, int size_y, float offset_x, float offset_y);
    Inventory();
    ~Inventory();

    void takeItem(int x, int y, bool quick = true);
    void dropItem(int x, int y, bool all = true);

    void takeAll();
    void dropAll();
};

class Chest : public Inventory {
   public:
    Chest() : Inventory{9, 3, -4, -3} {};
};

class DoubleChest : public Inventory {
   public:
    DoubleChest() : Inventory{9, 6, -4, -4.5f} {};
};

#endif
