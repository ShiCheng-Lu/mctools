#ifndef _SCREEN_H_
#define _SCREEN_H_

// #include <../coord.h>
#include <windows.h>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef uint32_t Color;

class Point {
   public:
    int x, y;
};

class Coord {
   public:
    int x, y, z;
};

std::ostream& operator<<(std::ostream& out, Color colour);

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
