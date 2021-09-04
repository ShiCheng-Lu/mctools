#include <iostream>
#include <vector>

#include "interface/keyboard.h"
#include "interface/mouse.h"

#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    
    std::this_thread::sleep_for(std::chrono::seconds(3));

    Mouse::move_to(1 << 15, (1 << 15) + (1 << 11));
    Keyboard::input('Q');
}
