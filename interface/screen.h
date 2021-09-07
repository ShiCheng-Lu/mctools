#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "../coord.h"
#include <windows.h>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef uint32_t Color;

// enable screen shots and watching the screen
class Screen {
    HWND window;

    int top, left;
    int width, height;

   public:
    Screen(std::string title);
    ~Screen();

    Color get_pixel(const int x, const int y);
    Color get_pixel(const Point& p);

    std::vector<std::vector<Color>> get_area();

    // check if the screen area matches exactly with a certain area
    bool compare();

    void update();

    Point get_size();
};

#endif
