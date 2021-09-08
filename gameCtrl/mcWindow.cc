#include "mcWindow.h"

#include "../utils/delay.h"
#include "../utils/keyboard.h"
#include "../utils/screen.h"

#include <iostream>

#include <chrono>

McWindow::McWindow() : ui_size{0} {
    rect = Screen::getWindowRect("Minecraft");

    // remove banner/title area
    center.x = (rect.left + rect.right) / 2;
    // while the sampled pixel is completely white
    while (Screen::getPixel(center.x, rect.top) == 0xffffff) {
        rect.top++;
    };

    // get ui_size
    Keyboard::click('E');
    center.y = (rect.top + rect.bottom) / 2;
    int test_y = center.y;
    // wait until the inventory pops up
    while (Screen::getPixel(center.x, test_y) != 0xc6c6c6) {
        Delay::ms(150);
    }
    while (Screen::getPixel(center.x, test_y) == 0xc6c6c6) {
        test_y--;
    }
    // can close the inventory here, as the delay is enough
    // to sample the rest of the ui_size as it's small
    Keyboard::click('E');

    while (Screen::getPixel(center.x, test_y - ui_size) == 0xffffff) {
        ui_size++;
    }

    width = rect.bottom - rect.top;
    height = rect.right - rect.left;

    std::cout << rect << '\n';
    std::cout << ui_size;
}

Point McWindow::getTopLeft() const {
    return Point{rect.left, rect.top};
}

Point McWindow::getCenter() const {
    // averages the rectagle
    return center;
}

Point McWindow::ui_scale(const Point& p) const {
    return p * ui_size;
}

void McWindow::update() {
    // nothing, might handle window moving
}