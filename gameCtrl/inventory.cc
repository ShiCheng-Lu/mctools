#include "inventory.h"
#include "../interface/delay.h"
#include "../interface/keyboard.h"
#include "../interface/mouse.h"
#include "menuCtrl.h"

Inventory::Inventory(int size_x, int size_y, float offset_x, float offset_y)
    : size_x{size_x}, size_y{size_y}, offset_x{offset_x}, offset_y{offset_y} {}

Inventory::Inventory() : size_x{9}, size_y{3}, offset_x{-4}, offset_y{0.5f} {}

Inventory::~Inventory() {}

void Inventory::takeItem(int x, int y, bool quick) {
    MenuCtrl::changeOffset(offset_x, offset_y);
    MenuCtrl::selectInv(x, y);
    MenuCtrl::takeItem(quick);
}
void Inventory::dropItem(int x, int y, bool all) {
    MenuCtrl::changeOffset(offset_x, offset_y);
    MenuCtrl::selectInv(x, y);
    MenuCtrl::dropItem(all);
}

void Inventory::takeAll() {
    Mouse::release(Mouse::LEFT);
    Mouse::release(Mouse::RIGHT);

    Keyboard::press(Keyboard::SHIFT);

    MenuCtrl::changeOffset(offset_x, offset_y);

    for (int y = 0; y < size_y; ++y) {
        for (int x = 0; x < size_x; ++x) {
            MenuCtrl::selectInv(x, y);
            Mouse::click(Mouse::LEFT);
            Delay::ms(17);
        }
    }
    Keyboard::click('E');
    Keyboard::release(Keyboard::SHIFT);
}
void Inventory::dropAll() {
    MenuCtrl::changeOffset(offset_x, offset_y);
}