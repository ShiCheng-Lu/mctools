#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

// this module simulate and listen for keyboard events

#include <chrono>
#include <cstdint>
#include <thread>

namespace Keyboard {

// simulate keyboard inputs
void input(const uint8_t key);

void press(const uint8_t key);

void release(const uint8_t key);

template <typename _Rep, typename _Period>
void hold(const uint8_t key,
                    std::chrono::duration<_Rep, _Period> time) {
    press(key);
    std::this_thread::sleep_for(time);
    release(key);
}

// get keyboard inputs
bool isDown(const uint8_t key);

bool isPressed(const uint8_t key);

void update();

}  // namespace Keyboard

#endif
