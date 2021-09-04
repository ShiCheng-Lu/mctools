#ifndef _ACTION_CONTROLLER_H_
#define _ACTION_CONTROLLER_H_

#include <utility>

class Item;

class ActionController {
    int inv_size_x;
    int inv_size_y;

    int inv_x_offset;
    int inv_y_offset;

    // position the mouse over the x, y coord in the inventory
    void selectInv(int x, int y);

   public:
    enum class InvType {
        Inventory,
        InventoryRecipe,
        Chest,
        DoubleChest,
    };

    void forallInv(void (*function)(int, int));

    void inventory();

    void mine();

    void place();

    void setInvType(InvType type);
};

void takeItem(int x, int y);
void dropItem(int x, int y);

#endif
