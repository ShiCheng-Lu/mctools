#include <windows.h>
#include <bitset>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "gameCtrl/inventory.h"
#include "gameCtrl/menuCtrl.h"
#include "gameCtrl/moveCtrl.h"
#include "gameCtrl/mcWindow.h"

#include "utils/keyboard.h"
#include "utils/mouse.h"
#include "utils/screen.h"
#include "utils/delay.h"

#include "dispatcher.h"
#include "strListener.h"


int main(int argc, char* argv[]) {
    auto ms_per_frame = std::chrono::milliseconds{200};
    // Keyboard::update();
    // Mouse::update();
    Screen::init();

    Delay::sec(1);
    std::cout << "started" << std::endl;

    McWindow win;

    // Screen sc{"Minecraft"};

    // std::cout << sc.getSize() << std::endl;
    // std::cout << sc.toScreen({0, 0}) << std::endl;

    // Dispatcher dispatcher;
    // TakeAllFromInv steal{sc};
    // dispatcher.registerAction(&steal);

    // StrListener cmdlistener{"/MCTOOLS"};

    // auto last = std::chrono::system_clock::now();
    // while (!Keyboard::isDown('\e')) {
    //     cmdlistener.update();
    //     dispatcher.update();

    //     if (Keyboard::isPressed('\r')) {
    //         std::cout << cmdlistener.getString();
    //         cmdlistener.clear();
    //     }

    //     Keyboard::update();
    //     Mouse::update();

    //     auto now = std::chrono::system_clock::now();
    //     if (now - last < ms_per_frame) {
    //         std::this_thread::sleep_for(now - last);
    //         last = now;
    //     }
    // }
}