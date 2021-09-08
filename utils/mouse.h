#ifndef _MOUSE_H_
#define _MOUSE_H_

// this module simulate and listen for mouse events

#include <cstdint>
#include "coord.h"

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

// |dx| |dy| are pixels
void move(const uint16_t dx, const uint16_t dy);
void move(const Point point);
// move to a location
void moveTo(const uint16_t dx, const uint16_t dy);
void moveTo(const Point point);

// GETTERS

// if the button is isPressed isDown
bool isDown(const uint8_t btn);

// if the button was isPressed since last update
bool isPressed(const uint8_t btn);

// INIT + UPDATE

void init();
void update();

}  // namespace Mouse

#endif
