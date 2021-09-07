#include "screen.h"

#include <windows.h>
#include <wingdi.h>

static int s_screen_count = 0;
static HDC s_screenDC;

Screen::Screen(const std::string title) {
    window = FindWindowA(nullptr, title.c_str());

    if (s_screen_count == 0) {
        s_screenDC = GetDC(NULL);
        s_screen_count++;
    }
}

Screen::~Screen() {
    s_screen_count--;
    if (s_screen_count == 0) {
        ReleaseDC(NULL, s_screenDC);
    }
}

Color Screen::get_pixel(const int x, const int y) {
    POINT p = {x, y};
    ClientToScreen(window, &p);
    return GetPixel(s_screenDC, p.x, p.y);
}

Color Screen::get_pixel(const Point& p) {
    return get_pixel(p.x, p.y);
}
