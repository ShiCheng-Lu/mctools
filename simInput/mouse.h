#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <cstdint>

#define mouse_left_press()      mouse_press(Mouse::LEFT)
#define mouse_left_release()    mouse_release(Mouse::LEFT)
#define mouse_left_click()      mouse_click(Mouse::LEFT)

#define mouse_right_press()     mouse_press(Mouse::RIGHT)
#define mouse_right_release()   mouse_release(Mouse::RIGHT)
#define mouse_right_click()     mouse_click(Mouse::RIGHT)

#define mouse_move_to(x, y)     mouse_move(x, y, true)

enum class Mouse {
    LEFT,
    RIGHT,
    MIDDLE,
};

// click the mouse button
void mouse_click(const Mouse but);

// press the mouse button
void mouse_press(const Mouse but);

// release the mouse button
void mouse_release(const Mouse but);

// |dx| |dy| are a 16 bit int from top left to bottom right,
// where 2^16, 2^16 would be the bottom right as percentages
void mouse_move(const uint16_t dx,
                const uint16_t dy,
                const bool absolute = false);

#endif
