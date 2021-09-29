#include "screen.h"

#ifndef NOMINMAX
#define NOMINMAX 1
#endif  // NOMINMAX

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
}

HDC captureDC;
HBITMAP hBitmap;
Point topleft;
Point size;

void setCaptureArea(Rect& r) {
    size.x = r.right - r.left;
    size.y = r.bottom - r.top;

    captureDC = CreateCompatibleDC(s_screenDC);
    hBitmap = CreateCompatibleBitmap(captureDC, size.x, size.y);
    SelectObject(captureDC, hBitmap);
}

void capture() {
    BitBlt(captureDC, 0, 0, s_width, s_height, s_screenDC, 0, 0, SRCCOPY);
}

Color getPixelFromCapture(const int x, const int y) {
    return GetPixel(captureDC, x, y);
}

Color getPixelFromCapture(const Point& p) {
    return GetPixel(captureDC, p.x, p.y);
}

}  // namespace Screen
