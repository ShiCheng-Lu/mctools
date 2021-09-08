#include "inventory.h"
#include "../utils/delay.h"
#include "../utils/keyboard.h"
#include "../utils/mouse.h"
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
    
}
void Inventory::dropAll() {
    MenuCtrl::changeOffset(offset_x, offset_y);
}