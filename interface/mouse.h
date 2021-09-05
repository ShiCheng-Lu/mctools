#ifndef _MOUSE_H_
#define _MOUSE_H_

// this module simulate and listen for mouse events

#include <cstdint>
#include <utility>

namespace Mouse {

const uint8_t LEFT = 0;
const uint8_t RIGHT = 1;
const uint8_t MIDDLE = 2;

// SETTERS

// click the mouse button
void click(const uint8_t btn);

// press the mouse button
void press(const uint8_t btn);

// release the mouse button
void release(const uint8_t btn);

// |dx| |dy| are a 16 bit int from top left to bottom right,
// where 2^16, 2^16 would be the bottom right as percentages
void move(const uint16_t dx, const uint16_t dy);
void move_to(const uint16_t dx, const uint16_t dy);

// GETTERS

// if the button is isPressed isDown
bool isDown(const uint8_t btn);

// if the button was isPressed since last update
bool isPressed(const uint8_t btn);

void update();

}  // namespace Mouse

#endif
