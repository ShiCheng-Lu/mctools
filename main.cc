#include <iostream>
#include <vector>

#include <thread>

#include "gameCtrl/inventory.h"
#include "gameCtrl/menuCtrl.h"
#include "gameCtrl/moveCtrl.h"

#include "interface/bitmap.h"
#include "interface/keyboard.h"
#include "interface/mouse.h"
#include "interface/screen.h"

#include <windows.h>
#include <bitset>
#include <chrono>
#include <thread>

void GetDesktopResolution(int& horizontal, int& vertical) {
    // RECT desktop;
    // // Get a handle to the desktop window
    // const HWND hDesktop = GetDesktopWindow();
    // // Get the size of screen to the variable desktop
    // GetWindowRect(hDesktop, &desktop);
    // horizontal = desktop.right;
    // vertical = desktop.bottom;

    // HMONITOR primary = MonitorFromPoint({0, 0}, MONITOR_DEFAULTTONEAREST);
    // MONITORINFO info{.cbSize = sizeof(MONITORINFO)};
    // std::cout << GetMonitorInfo(primary, &info) << std::endl;

    horizontal = GetSystemMetrics(SM_CXSCREEN);
    vertical = GetSystemMetrics(SM_CYSCREEN);
}

int main(int argc, char* argv[]) {
    int x, y;

    GetDesktopResolution(x, y);
    std::cout << x << ' ' << y;
}