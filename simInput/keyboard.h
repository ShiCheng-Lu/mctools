#include <cstdint>

class Keyboard {
   public:
    static void input(uint8_t key);
    static void press(uint8_t key);
    static void release(uint8_t key);
};
