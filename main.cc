#include <iostream>
#include <vector>

#include <thread>

#include "gameCtrl/menuCtrl.h"
#include "gameCtrl/moveCtrl.h"
#include "interface/keyboard.h"

int main(int argc, char* argv[]) {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    MenuCtrl::initialize(5);

    Keyboard::press(Keyboard::SHIFT);
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 9; ++x) {
            MenuCtrl::selectInv(x, y);
            MenuCtrl::takeItem();
            std::this_thread::sleep_for(std::chrono::milliseconds(37));
        }
    }
    Keyboard::release(Keyboard::SHIFT);

    // for (int i = 0; i < 50; ++i) {
    //     MoveCtrl::moveForward(1);
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
    // MoveCtrl::moveForward(100);
    // std::this_thread::sleep_for(std::chrono::seconds(30));
}