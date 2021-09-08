#include <windows.h>
#include <bitset>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "gameCtrl/inventory.h"
#include "gameCtrl/mcWindow.h"
#include "gameCtrl/menuCtrl.h"
#include "gameCtrl/moveCtrl.h"

#include "utils/delay.h"
#include "utils/keyboard.h"
#include "utils/mouse.h"
#include "utils/screen.h"

#include "dispatcher.h"
#include "strListener.h"

#include "features/steal.h"

int main(int argc, char* argv[]) {
    auto ms_per_frame = std::chrono::milliseconds{200};
    
    Keyboard::init();
    Mouse::init();
    Screen::init();

    Delay::sec(1);
    std::cout << "started" << std::endl;

    McWindow win;

    Dispatcher dispatcher;
    Steal steal{win};
    dispatcher.registerAction(&steal);

    StrListener cmdlistener{"/MCTOOLS"};

    auto last = std::chrono::system_clock::now();
    while (!Keyboard::isDown('\e')) {
        cmdlistener.update();
        dispatcher.update();

        if (Keyboard::isPressed('\r')) {
            std::cout << cmdlistener.getString();
            cmdlistener.clear();
        }

        Keyboard::update();
        Mouse::update();

        auto now = std::chrono::system_clock::now();
        if (now - last < ms_per_frame) {
            std::this_thread::sleep_for(now - last);
            last = now;
        }
    }
}