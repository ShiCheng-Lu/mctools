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

#define EXIT_TIMEOUT 5000

static int exit_timer = 0;
bool shouldExit(StrListener cmd_listener) {
    if (Keyboard::isPressed('\r')) {
        std::string cmd = cmd_listener.getContent();
        cmd_listener.clear();
        if (cmd == " EXIT\r" || cmd == " END\r") {
            return true;
        }
    }
    if (Keyboard::isDown('\e')) {
        exit_timer++;
        if (exit_timer >= EXIT_TIMEOUT) {
            // escape held for 5 seconds
            return true;
        }
    } else {
        exit_timer = 0;
    }
}

int main(int argc, char* argv[]) {
    auto ms_per_frame = std::chrono::milliseconds{200};

    Keyboard::init();
    Mouse::init();
    Screen::init();

    StrListener cmdlistener{"/MCTOOLS"};
    // wait for the command "/mctools start"
    while (true) {
        cmdlistener.update();

        if (Keyboard::isPressed('\r')) {
            std::string cmd = cmdlistener.getContent();
            if (cmd == " START\r") {
                break;
            }
        }
        if (shouldExit(cmdlistener)) {
            return 0;
        }
        Keyboard::update();
    }

    std::cout << "started" << std::endl;

    McWindow win;

    Dispatcher dispatcher;
    Steal steal{win};
    dispatcher.registerAction(&steal);

    std::cout << "initialization complete" << std::endl;

    while (true) {
        cmdlistener.update();
        dispatcher.update();
        if (shouldExit(cmdlistener)) {
            return 0;
        }
        Keyboard::update();
        Mouse::update();
    }
}