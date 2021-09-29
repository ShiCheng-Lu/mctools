#include "infinifly.h"
#include <iostream>
#include "delay.h"
#include "keyboard.h"
#include "mouse.h"

void InfiniFly::fly() {
    while (flying) {
        for (int i = 0; i < 12; ++i) {
            Mouse::move(0, -1);
            Delay::ms(100);
        }
        Delay::sec(4);
        if (!flying)
            break;
        for (int i = 0; i < 12; ++i) {
            Mouse::move(0, 1);
            Delay::ms(100);
        }
        Delay::sec(8);
    }
}

bool InfiniFly::condition() {
    if (Keyboard::isPressed('\r')) {
        std::string cmd = strListener.getContent();
        if (cmd == " FLY\r") {
            return true;
        }
    }
    return false;
}

void InfiniFly::operation() {
    flying = !flying;
    active = false;

    if (flying) {
        // setup 40:40 trick
        // look directly down
        Delay::sec(1);
        for (int i = 0; i < 20; ++i) {
            Mouse::move(0, 1);
            Delay::ms(50);
        }
        // look up ~ 60 degrees
        for (int i = 0; i < 8; ++i) {
            Mouse::move(0, -1);
            Delay::ms(50);
        }
        fly();
    }
}