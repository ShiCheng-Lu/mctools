#include "screen.h"

#include <windows.h>
#include <wingdi.h>
#include <algorithm>

namespace Screen {

static HDC s_screenDC;
static int s_width;
static int s_height;

Rect getWindowRect(const std::string title) {
    HWND hWnd = FindWindowA(NULL, title.c_str());

    WINDOWINFO wi;
    wi.cbSize = sizeof(WINDOWINFO);
    GetWindowInfo(hWnd, &wi);

    return Rect{
        std::max((int)wi.rcClient.left, 0),
        std::max((int)wi.rcClient.top, 0),
        std::min((int)wi.rcClient.right, s_width),
        std::min((int)wi.rcClient.bottom, s_height),
    };
}

Color getPixel(const int x, const int y) {
    return GetPixel(s_screenDC, x, y);
}

Color getPixel(const Point& p) {
    return GetPixel(s_screenDC, p.x, p.y);
}

Point getSize() {
    return Point{s_width, s_height};
}

void init() {
    s_screenDC = GetDC(NULL);
    s_width = GetDeviceCaps(s_screenDC, HORZRES);
    s_height = GetDeviceCaps(s_screenDC, VERTRES);
    // window = FindWindowA(nullptr, title.c_str());
    // RECT rect;
    // GetClientRect(window, &rect);
    // width = rect.right;
    // height = rect.bottom;

    // title_size = 0;

    // for (int i = 0; i < 100; ++i) {
    //     POINT p = {0, title_size};
    //     ClientToScreen(window, &p);
    //     Color c = GetPixel(s_screenDC, p.x, p.y);
    //     if (c != 0xdadada && c != 0xffffffff) {
    //         std::cout << std::hex << c << std::endl;
    //         std::cout << title_size << std::endl;
    //     } else {
    //         title_size++;
    //         height--;
    //     }
    // }
    // std::cout << title_size << std::endl;
}

}  // namespace Screen
