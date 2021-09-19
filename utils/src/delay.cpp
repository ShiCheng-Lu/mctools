#include "delay.h"

#include <chrono>
#include <thread>

namespace Delay {

void sec(int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void ms(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void us(int us) {
    std::this_thread::sleep_for(std::chrono::microseconds(us));
}

}  // namespace Delay
