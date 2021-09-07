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
#include "strListener.h"

class TakeAllFromInv : public Action {
    Screen& screen;
    int type = 0;

   public:
    TakeAllFromInv(Screen& screen) : screen{screen}, type{0} {}

    bool condition() override {
        if (!Keyboard::isPressed(' ')) {
            return false;
        }
        Color c = screen.get_pixel(1920, 1080);
        if (c == 0xc6c6c6) {
            type = 0;
            return true;
        } else if (c == 0x8b8b8b) {
            type = 1;
            return true;
        }
        return false;
    }
    void operation() override {
        switch (type) {
            case 0: {
                Chest c;
                c.takeAll();
                return;
            }

            case 1: {
                DoubleChest c;
                c.takeAll();
                return;
            }
            default:
                return;
        }
    }
};

int main(int argc, char* argv[]) {
    auto ms_per_frame = std::chrono::milliseconds{200};
    // Keyboard::update();
    // Mouse::update();
    Screen sc{"Minecraft"};

    Dispatcher dispatcher;
    TakeAllFromInv steal{sc};
    dispatcher.registerAction(&steal);

    StrListener cmdlistener{"/MCTOOLS"};

    auto last = std::chrono::system_clock::now();
    while (!Keyboard::isDown('\e')) {
        cmdlistener.update();
        dispatcher.update();
        
        if (Keyboard::isPressed('\r')) {
            std::cout << cmdlistener.getString();
            cmdlistener.clear();
        }

        Keyboard::update();
        Mouse::update();

        auto now = std::chrono::system_clock::now();
        if (now - last < ms_per_frame) {
            std::this_thread::sleep_for(now - last);
            last = now;
        }
    }
}