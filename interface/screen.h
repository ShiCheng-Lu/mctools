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

   public:
    Screen(std::string title);
    ~Screen();

    Color get_pixel(int x, int y);

    std::vector<std::vector<Color>> get_area();

    // check if the screen area matches exactly with a certain area
    bool compare();

    void update();

    Point get_size();
};

#endif
