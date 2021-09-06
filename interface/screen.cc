#include "screen.h"

#include <windows.h>
#include <wingdi.h>

std::ostream& operator<<(std::ostream& out, Colour& colour) {
    out << std::hex;
    out << (int)colour.r;
    out << (int)colour.g;
    out << (int)colour.b;
    out << std::dec;
    return out;
}

Screen::Screen(const std::string title) {
    HWND hWnd = FindWindowA(nullptr, title.c_str());

    HDC hSourceDC = GetDC(hWnd);
    HDC hTargetDC = CreateCompatibleDC(hSourceDC);

    int width = 50;
    int height = 50;

    HBITMAP hBitmap = CreateCompatibleBitmap(hTargetDC, width, height);
}

void capture() {
    HWND hWnd = FindWindowA(NULL, "Minecraft");

    HDC hWindowDC = GetDC(hWnd);
    HDC hTargetDC = CreateCompatibleDC(hWindowDC);

    RECT size;
    GetClientRect(hWnd, &size);

    std::cout << size.right << " " << size.bottom << std::endl;

    size.right *= 2.5;
    size.bottom *= 2.5;

    HBITMAP hBitmap =
        CreateCompatibleBitmap(hWindowDC, size.right, size.bottom);

    //     // use the previously created device context with the bitmap
    HGDIOBJ old_obj = SelectObject(hTargetDC, hBitmap);

    //     // SetStretchBltMode(hWindowDC, HALFTONE);
    BitBlt(hTargetDC, 0, 0, size.right, size.bottom, hWindowDC, 0, 0, SRCCOPY);

    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(CF_BITMAP, hBitmap);
    CloseClipboard();

    SelectObject(hTargetDC, old_obj);

    ReleaseDC(NULL, hWindowDC);

    // DeleteObject(hImage);
    DeleteDC(hTargetDC);
    std::cout << "complete";
}
