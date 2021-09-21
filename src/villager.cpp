#include "villager.h"

#include <iostream>
#include "keyboard.h"
#include "mcWindow.h"
#include "mouse.h"
#include "screen.h"

void VillagerTrader::checkTrade() {}

void VillagerTrader::waitForJob() {
    while (running && Screen::getPixel(win.getCenter()) != 0xffffff) {
        Mouse::click(Mouse::RIGHT);
        if (Keyboard::isDown('/')) {
            running = false;
        }
    }
}

void VillagerTrader::addTarget() {}

bool VillagerTrader::condition() {
    if (Keyboard::isPressed('\r')) {
        std::string cmd = listener.getContent();
        return (cmd == " VILLAGER\r");
    }
    return false;
}

void VillagerTrader::operation() {
    running = true;
    std::cout << "villager trader started" << std::endl;
    while (running) {
        waitForJob();
    }
}
