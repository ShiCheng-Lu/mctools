#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <cstdint>

namespace Keyboard {

// simulate keyboard inputs
void input(const uint8_t key);

void press(const uint8_t key);

void release(const uint8_t key);

// get keyboard inputs
bool down(const uint8_t key);

bool pressed(const uint8_t key);

}  // namespace Keyboard

#endif
