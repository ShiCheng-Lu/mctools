#include <iostream>
#include <vector>

#include <thread>

#include "gameCtrl/inventory.h"
#include "gameCtrl/menuCtrl.h"
#include "gameCtrl/moveCtrl.h"

#include "interface/bitmap.h"
#include "interface/keyboard.h"
#include "interface/mouse.h"
#include "interface/screen.h"

#include <windows.h>
#include <bitset>
#include <chrono>
#include <thread>

void takeAllListener() {
    if (Keyboard::isDown(Keyboard::SHIFT) && Keyboard::isDown('R')) {
        Inventory inv;
        inv.takeAll();
        MenuCtrl::openInventory(); // also closes the inventory (same button)
    }
}

int main(int argc, char* argv[]) {
    auto last = std::chrono::system_clock::now();

    auto ms_per_frame = std::chrono::milliseconds{166};

    while (!Keyboard::isDown('\e')) {
        takeAllListener();

        Keyboard::update();
        Mouse::update();
        auto now = std::chrono::system_clock::now();
        if (now - last < ms_per_frame) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            last = now;
        }
    }
}