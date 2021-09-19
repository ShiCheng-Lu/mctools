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

static bool running = true;

static int exit_timer = 0;
bool checkExitCondition(StrListener cmd_listener) {
    if (Keyboard::isPressed('\r')) {
        std::string cmd = cmd_listener.getContent();
        cmd_listener.clear();
        if (cmd == " EXIT\r" || cmd == " END\r") {
            running = false;
        }
    }
    if (Keyboard::isDown('\e')) {
        exit_timer++;
        if (exit_timer >= EXIT_TIMEOUT) {
            // escape held for 5 seconds
            running = false;
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
    while (running) {
        cmdlistener.update();

        if (Keyboard::isPressed('\r')) {
            std::string cmd = cmdlistener.getContent();
            if (cmd == " START\r") {
                break;
            }
        }
        checkExitCondition(cmdlistener);
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

    while (running) {
        cmdlistener.update();
        dispatcher.update();
        
        checkExitCondition(cmdlistener);
        
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