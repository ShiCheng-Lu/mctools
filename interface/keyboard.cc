#include "keyboard.h"

#include <windows.h>
#include <chrono>
#include <thread>

static uint8_t get_id(const uint8_t key) {
    if (key == '/') {
        return VK_OEM_2;
    }
    return key;
}

void Keyboard::input(const uint8_t key) {
    uint8_t key_id = get_id(key);

    Keyboard::press(key_id);
    Keyboard::release(key_id);
}

void Keyboard::press(const uint8_t key) {
    uint8_t key_id = get_id(key);

    keybd_event(key_id, 0, 0, 0);
}

void Keyboard::release(const uint8_t key) {
    uint8_t key_id = get_id(key);

    keybd_event(key_id, 0, 0, 0);
}
