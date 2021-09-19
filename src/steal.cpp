#include "steal.h"

#include "delay.h"
#include "keyboard.h"
#include "mouse.h"
#include "screen.h"

#define SLOT_SIZE 18

void Steal::takeAll(const Point& inv_size, const Point& offset) {
    Mouse::release(Mouse::LEFT);
    Mouse::release(Mouse::RIGHT);

    Keyboard::press(Keyboard::SHIFT);

    Point pixel_offset = win.getCenter() + win.ui_scale(offset);

    for (int y = 0; y < inv_size.y * SLOT_SIZE; y += SLOT_SIZE) {
        for (int x = 0; x < inv_size.x * SLOT_SIZE; x += SLOT_SIZE) {
            Point p = win.ui_scale(Point{x, y}) + pixel_offset;
            Mouse::moveTo(p);
            Mouse::click(Mouse::LEFT);
            Delay::ms(17);
        }
    }
    Keyboard::click('E');
    Keyboard::release(Keyboard::SHIFT);
}

bool Steal::condition() {
    if (!Keyboard::isPressed(' ')) {
        return false;
    }
    Color c = Screen::getPixel(win.getCenter());
    std::cout << std::hex << c << std::endl;

    if (c == 0xc6c6c6) {
        type = 0;
        return true;
    } else if (c == 0xffffff || c == 0x8b8b8b) {
        // is a double chest
        type = 1;
        return true;
    }
    return false;
}
void Steal::operation() {
    switch (type) {
        case 0: {
            takeAll(Point{9, 3}, Point{SLOT_SIZE * -4, SLOT_SIZE * -3});
            return;
        }

        case 1: {
            takeAll(Point{9, 6},
                    Point{SLOT_SIZE * -4, (int)(SLOT_SIZE * -4.5)});
            return;
        }
        default:
            return;
    }
}
