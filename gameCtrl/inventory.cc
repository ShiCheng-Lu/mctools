#include "inventory.h"
#include "menuCtrl.h"
#include "../interface/keyboard.h"
#include "../interface/mouse.h"
#include "../interface/delay.h"

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
    MenuCtrl::changeOffset(offset_x, offset_y);
    Keyboard::press(Keyboard::SHIFT);
    for (int y = 0; y < size_y; ++y) {
        for (int x = 0; x < size_x; ++x) {
            MenuCtrl::selectInv(x, y);
            Mouse::click(Mouse::LEFT);
            Delay::ms(37);
        }
    }
    Keyboard::press(Keyboard::SHIFT);
}
void Inventory::dropAll() {
    MenuCtrl::changeOffset(offset_x, offset_y);
}