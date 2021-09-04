#include "keyboard.h"

#include <windows.h>
#include <thread>
#include <chrono>

void key_input(uint8_t key) {
    key_press(key);
    // std::this_thread::sleep_for(std::chrono::microseconds(16667));
    key_release(key);
}

void key_press(uint8_t key) {
    keybd_event(key, 0, 0, 0);
}

void key_release(uint8_t key) {
    keybd_event(key, 0, 0, 0);
}
