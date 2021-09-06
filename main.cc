#include <iostream>
#include <vector>

#include <thread>

#include "gameCtrl/menuCtrl.h"
#include "gameCtrl/moveCtrl.h"

#include "interface/bitmap.h"
#include "interface/keyboard.h"
#include "interface/mouse.h"
#include "interface/screen.h"

#include <windows.h>
#include <wingdi.h>

int main(int argc, char* argv[]) {
    // capture();

    HDC scr = GetDC(nullptr);

    std::cout << GetDeviceCaps(scr, HORZRES) << std::endl
              << GetDeviceCaps(scr, HORZSIZE) << std::endl
              << GetSystemMetrics(SM_XVIRTUALSCREEN) << std::endl
              << GetSystemMetrics(SM_YVIRTUALSCREEN) << std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(3));
    // MenuCtrl::initialize(5);

    // Keyboard::press(Keyboard::SHIFT);
    // for (int y = 0; y < 3; ++y) {
    //     for (int x = 0; x < 9; ++x) {
    //         MenuCtrl::selectInv(x, y);
    //         MenuCtrl::takeItem();
    //         std::this_thread::sleep_for(std::chrono::milliseconds(37));
    //     }
    // }
    // Keyboard::release(Keyboard::SHIFT);

    // Mouse::move_to(1 << 15, 1 << 15);

    // for (int i = 0; i < 50; ++i) {
    //     MoveCtrl::moveForward(1);
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
    // MoveCtrl::moveForward(100);
    // std::this_thread::sleep_for(std::chrono::seconds(30));
}