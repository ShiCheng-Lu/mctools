#include "mouse.h"

#include <windows.h>
#include <bitset>
#include <map>

// SETTERS

static const std::map<uint8_t, uint16_t> s_event_up = {
    {Mouse::LEFT, MOUSEEVENTF_LEFTUP},
    {Mouse::RIGHT, MOUSEEVENTF_RIGHTUP},
    {Mouse::MIDDLE, MOUSEEVENTF_MIDDLEUP},
};

static const std::map<uint8_t, uint16_t> s_event_down = {
    {Mouse::LEFT, MOUSEEVENTF_LEFTDOWN},
    {Mouse::RIGHT, MOUSEEVENTF_RIGHTDOWN},
    {Mouse::MIDDLE, MOUSEEVENTF_MIDDLEDOWN},
};

// click the mouse button
void Mouse::click(const uint8_t btn) {
    mouse_event(s_event_up.at(btn) | s_event_up.at(btn), 0, 0, 0, 0);
}

// press the mouse button
void Mouse::press(const uint8_t btn) {
    mouse_event(s_event_down.at(btn), 0, 0, 0, 0);
}

// release the mouse button
void Mouse::release(const uint8_t btn) {
    mouse_event(s_event_up.at(btn), 0, 0, 0, 0);
}

// |dx| |dy| are a 16 bit int from top left to bottom right,
// where 2^16, 2^16 would be the bottom right as percentages
void Mouse::move(const uint16_t dx, const uint16_t dy) {
    mouse_event(MOUSEEVENTF_MOVE, dx, dy, 0, 0);
}
void Mouse::move_to(const uint16_t x, const uint16_t y) {
    mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, x, y, 0, 0);
}

// GETTERS
#define BUTTONS_MAX 3

static std::bitset<BUTTONS_MAX> processed;
static std::bitset<BUTTONS_MAX> downed;

bool Mouse::down(const uint8_t btn) {
    return downed.test(btn);
}

bool Mouse::pressed(const uint8_t btn) {
    if (!processed[btn]) {
        processed.set(btn);
        return downed.test(btn);
    }
    return false;
}

void Mouse::update() {
    processed.reset();
    downed.reset();

    for (int i = 0; i < BUTTONS_MAX; ++i) {
        continue;
    }
}
