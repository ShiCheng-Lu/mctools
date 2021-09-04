#include <iostream>
#include <vector>

#include "interface/keyboard.h"
#include "interface/mouse.h"

#include <chrono>
#include <thread>

#include "gameCtrl/menuCtrl.h"

const int ui_size = 5;

int main(int argc, char* argv[]) {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    MenuCtrl::initialize(5);

    // for (int y = 0; y < 2; ++y) {
    //     for (int x = 0; x < 5; ++x) {
    //         MenuCtrl::selectInv(x, y);
    //         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //     }
    // }
    Keyboard::hold('W', std::chrono::seconds(1));
}
