#include "mouse.h"

#include <windows.h>
#include <bitset>
#include <map>

namespace Mouse {

// SETTERS

static const std::map<uint8_t, uint16_t> s_event_up = {
    {LEFT, MOUSEEVENTF_LEFTUP},
    {RIGHT, MOUSEEVENTF_RIGHTUP},
    {MIDDLE, MOUSEEVENTF_MIDDLEUP},
};

static const std::map<uint8_t, uint16_t> s_event_down = {
    {LEFT, MOUSEEVENTF_LEFTDOWN},
    {RIGHT, MOUSEEVENTF_RIGHTDOWN},
    {MIDDLE, MOUSEEVENTF_MIDDLEDOWN},
};

// click the mouse button
void click(const uint8_t btn) {
    mouse_event(s_event_down.at(btn) | s_event_up.at(btn), 0, 0, 0, 0);
}

// press the mouse button
void press(const uint8_t btn) {
    mouse_event(s_event_down.at(btn), 0, 0, 0, 0);
}

// release the mouse button
void release(const uint8_t btn) {
    mouse_event(s_event_up.at(btn), 0, 0, 0, 0);
}

// |dx| |dy| are a 16 bit int from top left to bottom right,
// where 2^16, 2^16 would be the bottom right as percentages
void move(const uint16_t dx, const uint16_t dy) {
    mouse_event(MOUSEEVENTF_MOVE, dx, dy, 0, 0);
}
void move_to(const uint16_t x, const uint16_t y) {
    mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, x, y, 0, 0);
}

// GETTERS

static std::bitset<3> pressed;
static std::bitset<3> btnDown;
static bool recording = false;

bool isDown(const uint8_t btn) {
    return btnDown.test(btn);
}

bool isPressed(const uint8_t btn) {
    if (!pressed.test(btn)) {
        pressed.set(btn);
        return btnDown.test(btn);
    }
    return false;
}

void update() {
    btnDown.reset();

    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
        btnDown.set(LEFT);
    } else {
        pressed.reset(LEFT);
    }
    if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
        btnDown.set(RIGHT);
    } else {
        pressed.reset(RIGHT);
    }
    if (GetAsyncKeyState(VK_MBUTTON) & 0x8000) {
        btnDown.set(MIDDLE);
    } else {
        pressed.reset(MIDDLE);
    }
}

}  // namespace Mouse
