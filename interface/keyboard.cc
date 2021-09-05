#include "keyboard.h"

#include <windows.h>
#include <bitset>

#define KEY_MAX 256

namespace Keyboard {

// SETTERS

static uint8_t get_id(const uint8_t key) {
    if (key == '/') {
        return VK_OEM_2;
    }
    return key;
}

void input(const uint8_t key) {
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

static std::bitset<KEY_MAX> processed;
static std::bitset<KEY_MAX> keyDown;

bool isDown(const uint8_t key) {
    uint8_t key_id = get_id(key);
    return keyDown.test(key_id);
}

bool isPressed(const uint8_t key) {
    uint8_t key_id = get_id(key);
    if (!processed.test(key_id)) {
        processed.set(key_id);
        return keyDown.test(key_id);
    }
    return false;
}

void update() {
    processed.reset();
    keyDown.reset();

    for (int i = 0; i < KEY_MAX; ++i) {
        continue;
    }
}

}  // namespace Keyboard
