#include "actionController.h"
#include "mouse.h"
#include "keyboard.h"

#include <windows.h>

void ActionController::forallInv(void (*function)(int, int)) {
    for (int y = 0; y < inv_size_y; ++y) {
        for (int x = 0; x < inv_size_x; ++x) {

            function(x, y);
        }
    }
}

void ActionController::inventory() {}

void ActionController::mine() {}

void ActionController::place() {}

void ActionController::setInvType(InvType type) {
    switch (type) {
        case InvType::Chest:
            inv_size_x = 9;
            inv_size_y = 3;
            break;
        case InvType::DoubleChest:
            inv_size_x = 9;
            inv_size_y = 6;
            break;
        case InvType::Inventory:
            inv_size_x = 9;
            inv_size_y = 4;
            break;
        case InvType::InventoryRecipe:
            inv_size_x = 9;
            inv_size_y = 4;
            break;

        default:
            break;
    }
}

void takeItem(int x, int y) {
    Mouse::click(Mouse::Button::LEFT);
    Sleep(34); // 34 ms is two frames, needed for minecraft to pick up the english
}

void dropItem(int x, int y) {
    Keyboard::input('Q');
}
