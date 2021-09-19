#include "moveCtrl.h"

#include <chrono>
#include <thread>
#include "keyboard.h"

const int us_per_block = 231642;
const int us_mod = 230;

static void step_for(const int blocks, const char dir) {
    std::chrono::microseconds time(us_per_block * blocks - us_mod);

    std::thread walker([dir, time]() {
        Keyboard::press(dir);
        std::this_thread::sleep_for(time);
        Keyboard::release(dir);
    });
    walker.detach();
}

void MoveCtrl::moveForward(const int blocks) {
    step_for(blocks, 'W');
}

void MoveCtrl::moveBackward(int blocks) {
    step_for(blocks, 'S');
}

// strafe a number of blocks
void MoveCtrl::strafeLeft(int blocks) {
    step_for(blocks, 'A');
}
void MoveCtrl::strafeRight(int blocks) {
    step_for(blocks, 'D');
}

void beginSprint();

void endSprint();

void jump();