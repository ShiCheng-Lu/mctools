#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
#include <string>
#include <vector>

struct Colour {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

std::ostream& operator<<(std::ostream& out, Colour& colour);

// enable screen shots and watching the screen
class Screen {
    int dpi = 1;

   public:
    Screen(std::string);
    ~Screen();

    Colour get_pixel(int x, int y);

    std::vector<std::vector<Colour>> get_area();

    // check if the screen area matches exactly with a certain area
    bool compare();

    std::string parseString();

    void update();
};

#endif
