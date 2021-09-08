// #include "steal.h"
// #include "action.h"

// #include "../utils/delay.h"
// #include "../utils/mouse.h"
// #include "../utils/keyboard.h"
// #include "../gameCtrl/menuCtrl.h"

// static void takeAll() {
//     Mouse::release(Mouse::LEFT);
//     Mouse::release(Mouse::RIGHT);

//     Keyboard::press(Keyboard::SHIFT);

//     MenuCtrl::changeOffset(offset_x, offset_y);

//     for (int y = 0; y < size_y; ++y) {
//         for (int x = 0; x < size_x; ++x) {
//             MenuCtrl::selectInv(x, y);
//             Mouse::click(Mouse::LEFT);
//             Delay::ms(17);
//         }
//     }
//     Keyboard::click('E');
//     Keyboard::release(Keyboard::SHIFT);
// }

// class Steal : public Action {
//     Screen& screen;
//     int type = 0;

//    public:
//     Steal(Screen& screen) : screen{screen}, type{0} {}

//     bool condition() override {
//         if (!Keyboard::isPressed(' ')) {
//             return false;
//         }
//         Color c = screen.getPixel(screen.getSize() / 2);
//         std::cout << std::hex << c << std::endl;

//         if (c == 0xc6c6c6) {
//             type = 0;
//             return true;
//         } else if (c == 0xffffff) {
//             type = 1;
//             return true;
//         }
//         return false;
//     }
//     void operation() override {
//         switch (type) {
//             case 0: {
//                 Chest c;
//                 c.takeAll();
//                 return;
//             }

//             case 1: {
//                 DoubleChest c;
//                 c.takeAll();
//                 return;
//             }
//             default:
//                 return;
//         }
//     }
// };