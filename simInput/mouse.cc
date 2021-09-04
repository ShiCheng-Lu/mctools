#include "mouse.h"

#include <windows.h>
#include <map>

static const std::map<Mouse, uint16_t> s_event_up = {
    {Mouse::LEFT, MOUSEEVENTF_LEFTUP},
    {Mouse::RIGHT, MOUSEEVENTF_RIGHTUP},
    {Mouse::MIDDLE, MOUSEEVENTF_MIDDLEUP},
};

static const std::map<Mouse, uint16_t> s_event_down = {
    {Mouse::LEFT, MOUSEEVENTF_LEFTDOWN},
    {Mouse::RIGHT, MOUSEEVENTF_RIGHTDOWN},
    {Mouse::MIDDLE, MOUSEEVENTF_MIDDLEDOWN},
};

// click the mouse button
void mouse_click(const Mouse but) {
    mouse_event(s_event_up.at(but) | s_event_up.at(but), 0, 0, 0, 0);
}

// press the mouse button
void mouse_press(const Mouse but) {
    mouse_event(s_event_down.at(but), 0, 0, 0, 0);
}

// release the mouse button
void mouse_release(const Mouse but) {
    mouse_event(s_event_up.at(but), 0, 0, 0, 0);
}

// |dx| |dy| are a 16 bit int from top left to bottom right,
// where 2^16, 2^16 would be the bottom right as percentages
void mouse_move(const uint16_t dx, const uint16_t dy, const bool absolute) {
    uint16_t event_flag = MOUSEEVENTF_MOVE;
    if (absolute) {
        event_flag = event_flag | MOUSEEVENTF_ABSOLUTE;
    }
    mouse_event(event_flag, dx, dy, 0, 0);
}
