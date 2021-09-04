#include <iostream>
#include <vector>

#include "simInput/keyboard.h"

#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    
    std::this_thread::sleep_for(std::chrono::seconds(5));

    key_input('Q');
}
