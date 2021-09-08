#ifndef _SCREEN_H_
#define _SCREEN_H_

// enable sampling pixels of the screen
// and finding windows with related coords
// NOTE: only for primary window

#include <cstdint>
#include <string>
#include "coord.h"

// usually 24 bit integer for RGB, the high bit is not used
typedef uint32_t Color;

namespace Screen {

void init();

Rect getWindowRect(const std::string title);

Color getPixel(const int x, const int y);
Color getPixel(const Point& p);

Point getSize();

}  // namespace Screen

#endif
