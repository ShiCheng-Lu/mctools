#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

// this module simulate and listen for keyboard events

#include <chrono>
#include <cstdint>
#include <thread>

namespace Keyboard {

const uint8_t CONTROL = 0x11;
const uint8_t SHIFT = 0x10;

// simulate keyboard inputs
void input(const uint8_t key);

void press(const uint8_t key);

void release(const uint8_t key);

// get keyboard inputs
bool isDown(const uint8_t key);

bool isPressed(const uint8_t key);

void update();

}  // namespace Keyboard

#endif
