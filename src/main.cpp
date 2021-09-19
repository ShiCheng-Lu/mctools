#include <windows.h>
#include <bitset>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "inventory.h"
#include "mcWindow.h"
#include "menuCtrl.h"
#include "moveCtrl.h"

#include "delay.h"
#include "keyboard.h"
#include "mouse.h"
#include "screen.h"

#include "dispatcher.h"
#include "strListener.h"

#include "steal.h"

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

bool initialize() {
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
            return false;
        }
        Keyboard::update();
    }
    return true;
}

void process() {
    auto ms_per_frame = std::chrono::milliseconds{200};
    McWindow win;

    Dispatcher dispatcher;
    Steal steal{win};
    dispatcher.registerAction(&steal);

    StrListener cmdlistener{"/MCTOOLS"};

    while (true) {
        cmdlistener.update();
        dispatcher.update();
        if (shouldExit(cmdlistener)) {
            return;
        }
        Keyboard::update();
        Mouse::update();
    }
}

void cleanUp() {
    // nothing for now
}

int main(int argc, char* argv[]) {
    if (initialize()) {
        process();
    }

    cleanUp();
}