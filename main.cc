#include <windows.h>
#include <bitset>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "gameCtrl/inventory.h"
#include "gameCtrl/menuCtrl.h"
#include "gameCtrl/moveCtrl.h"

#include "interface/bitmap.h"
#include "interface/keyboard.h"
#include "interface/mouse.h"
#include "interface/screen.h"

#include "dispatcher.h"

int main(int argc, char* argv[]) {
    auto last = std::chrono::system_clock::now();

    auto ms_per_frame = std::chrono::milliseconds{166};
    // Keyboard::update();
    // Mouse::update();
    Screen sc{"Minecraft"};

    Dispatcher dispatcher;
    dispatcher.registerCallback(
        [](void* psc) {
            Screen* sc = (Screen*)psc;
            return Keyboard::isPressed(' ') &&
                   sc->get_pixel(1920, 1080) == 0xc6c6c6;
        },
        [](void* _) {
            Chest inv;
            inv.takeAll();
        },
        &sc);

    dispatcher.registerCallback(
        [](void* psc) {
            Screen* sc = (Screen*)psc;
            return Keyboard::isPressed(' ') &&
                   sc->get_pixel(1920, 1060) == 0x8b8b8b;
        },
        [](void* _) {
            DoubleChest inv;
            inv.takeAll();
        },
        &sc);

    while (!Keyboard::isDown('\e')) {
        dispatcher.update();
        Keyboard::update();
        Mouse::update();
        auto now = std::chrono::system_clock::now();
        if (now - last < ms_per_frame) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            last = now;
        }
    }
}