#include <windows.h>
#include <bitset>
#include <chrono>
#include <iomanip>
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

#include "infinifly.h"
#include "steal.h"
#include "villager.h"

#define EXIT_TIMEOUT 200

static bool running = true;

static int frames = 0;

void add_frame() {
    frames++;
    Delay::sec(1);
    frames--;
}

void update_frame() {
    std::thread t(add_frame);
    t.detach();
    std::cout << std::dec << std::setw(5) << '\r' << frames << std::flush;
}

static int exit_timer = 0;
void checkExitCondition(StrListener& cmd_listener) {
    if (Keyboard::isPressed('\r')) {
        std::string cmd = cmd_listener.getContent();
        std::cout << cmd << std::endl;
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

void initialize() {
    if (!running) {
        return;
    }

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
                return;
            }
        }
        checkExitCondition(cmdlistener);
        Keyboard::update();

        update_frame();

        Delay::ms(20);
    }
}

void process() {
    if (!running) {
        return;
    }
    auto ms_per_frame = std::chrono::milliseconds{200};
    McWindow win;
    StrListener cmdlistener{"/MCTOOLS"};

    Dispatcher dispatcher;
    Steal steal{win};
    dispatcher.registerAction(&steal);

    VillagerTrader villager{win, cmdlistener};
    dispatcher.registerAction(&villager);

    InfiniFly infiniFly{cmdlistener};
    dispatcher.registerAction(&infiniFly);

    while (running) {
        cmdlistener.update();
        dispatcher.update();

        checkExitCondition(cmdlistener);

        Keyboard::update();
        Mouse::update();

        update_frame();

        Delay::ms(20);
    }
}

void cleanUp() {
    // nothing for now
}

int main(int argc, char* argv[]) {
    std::cout << "program started" << std::endl;
    initialize();
    std::cout << "tool started" << std::endl;
    process();

    cleanUp();
}