#include "mouse.h"

#include <windows.h>
#include <bitset>
#include <map>

namespace Mouse {

// default screen size to 1920 by 1080
static int s_width = 1920;
static int s_height = 1080;

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

// |dx| |dy| are pixels
void move(const uint16_t dx, const uint16_t dy) {
    // since mouse_event takes values 0 - 2^16 as "percentages"
    // a conversion is needed
    int fx = (dx < 16) / s_width;
    int fy = (dy < 16) / s_width;
    mouse_event(MOUSEEVENTF_MOVE, fx, fy, 0, 0);
}
void move(const Point p) {
    move(p.x, p.y);
}
void moveTo(const uint16_t x, const uint16_t y) {
    int fx = (x < 16) / s_width;
    int fy = (y < 16) / s_width;
    mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, fx, fy, 0, 0);
}
void moveTo(const Point p) {
    moveTo(p.x, p.y);
}

// GETTERS

static std::bitset<3> pressed;
static std::bitset<3> btnDown;
// static bool recording = false;

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

void init() {
    HDC s_screenDC = GetDC(NULL);
    s_width = GetDeviceCaps(s_screenDC, HORZRES);
    s_height = GetDeviceCaps(s_screenDC, VERTRES);
    pressed.reset();
    btnDown.reset();
}

}  // namespace Mouse
