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

class InvOpenButton : public Trigger {
    uint8_t button;  // button is pressed

    Point point;  // point has color
    Color color;
    Screen& screen;

   public:
    InvOpenButton(uint8_t button, Point point, Color color, Screen& screen)
        : button{button}, point{point}, color{color}, screen{screen} {}
    bool operator()() override {
        if (Keyboard::isPressed(button) &&
            screen.get_pixel(point.x, point.y) == color) {
            return true;
        }
        return false;
    }
};

class TakeAllFromInv : public Action {
    Inventory& inv;

   public:
    TakeAllFromInv(Inventory inv) : inv{inv} {}
    void operator()() override { inv.takeAll(); }
};

int main(int argc, char* argv[]) {
    auto last = std::chrono::system_clock::now();

    auto ms_per_frame = std::chrono::milliseconds{200};
    // Keyboard::update();
    // Mouse::update();
    Screen sc{"Minecraft"};

    int x = 1920;
    int y = 1080;

    Dispatcher dispatcher;
    InvOpenButton chestOpened{' ', {x, y}, 0xc6c6c6, sc};
    TakeAllFromInv takeAllFromChest{Chest{}};
    dispatcher.registerCallback(&chestOpened, &takeAllFromChest);

    InvOpenButton doubleChestOpened{' ', {x, y}, 0x8b8b8b, sc};
    TakeAllFromInv takeAllDoubleChest{DoubleChest{}};
    dispatcher.registerCallback(&doubleChestOpened, &takeAllDoubleChest);

    while (!Keyboard::isDown('\e')) {
        dispatcher.update();
        Keyboard::update();
        Mouse::update();
        auto now = std::chrono::system_clock::now();
        if (now - last < ms_per_frame) {
            std::this_thread::sleep_for(now - last);
            last = now;
        }
    }
}