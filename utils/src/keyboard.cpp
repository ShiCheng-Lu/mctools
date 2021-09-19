#include "keyboard.h"

#include <windows.h>
#include <bitset>

#define KEY_MAX 0xff

namespace Keyboard {

// SETTERS

static uint8_t get_id(const uint8_t key) {
    if (key == '/') {
        return VK_OEM_2;
    }
    return key;
}

void click(const uint8_t key) {
    uint8_t key_id = get_id(key);
    press(key_id);
    release(key_id);
}

void press(const uint8_t key) {
    uint8_t key_id = get_id(key);
    keybd_event(key_id, 0, 0, 0);
}

void release(const uint8_t key) {
    uint8_t key_id = get_id(key);
    keybd_event(key_id, 0, KEYEVENTF_KEYUP, 0);
}

// GETTERS

static std::bitset<KEY_MAX> pressed;
static std::bitset<KEY_MAX> keyDown;

bool isDown(const uint8_t key) {
    uint8_t key_id = get_id(key);
    return keyDown.test(key_id);
}

bool isPressed(const uint8_t key) {
    uint8_t key_id = get_id(key);
    return pressed.test(key_id);
}

// INIT + UPDATE

void init() {
    keyDown.reset();
    pressed.reset();
}

void update() {
    keyDown.reset();
    pressed.reset();

    for (int key = 0; key < KEY_MAX; ++key) {
        SHORT state = GetAsyncKeyState(key);
        if (state & 0x8000) {
            keyDown.set(key);
        }
        if (state & 0x0001) {
            pressed.set(key);
        }
    }
}

}  // namespace Keyboard
