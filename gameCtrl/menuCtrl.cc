#include "menuCtrl.h"
#include <cstdint>
#include <utility>
#include "../interface/keyboard.h"
#include "../interface/mouse.h"

#define CENTER \
    { 0x8000, 0x8000 }
#define SLOT_SIZE 18

static int s_ui_scale = 1;
static int s_screen_w = 3840;
static int s_screen_h = 2160;

static int s_window_w = 3840;
static int s_window_h = 2160;

static int s_window_x = 0;
static int s_window_y = 0;

static int s_inv_offset_x = SLOT_SIZE / 2;
static int s_inv_offset_y = SLOT_SIZE * -4;

void toScreen(const std::pair<uint16_t, uint16_t>& percent,
              const std::pair<int, int>& pixels,
              std::pair<uint16_t, uint16_t>& result) {
    result = {0, 0};  // reset result incase it's not clean
    // add percent component
    result.first += percent.first * s_window_w / s_screen_w;
    result.second += percent.second * s_window_h / s_screen_h;
    // add window position offset;
    result.first += s_window_x;
    result.second += s_window_y;
    // add pixels offset
    result.first += 0x10000 * pixels.first / s_screen_w;
    result.second += 0x10000 * pixels.second / s_screen_h;
}

void MenuCtrl::openInventory() {}

void MenuCtrl::selectInv(int x, int y) {
    std::pair<int, int> offset = {
        (x * SLOT_SIZE + s_inv_offset_x) * s_ui_scale,
        (y * SLOT_SIZE + s_inv_offset_y) * s_ui_scale};
    std::pair<uint16_t, uint16_t> res;
    toScreen(CENTER, offset, res);
    Mouse::move_to(res.first, res.second);
}

void MenuCtrl::dropItem(bool all) {
    if (all) {
        Keyboard::press(Keyboard::CONTROL);
        Keyboard::input('Q');
        Keyboard::release(Keyboard::CONTROL);
    } else {
        Keyboard::input('Q');
    }
}

void MenuCtrl::takeItem(bool quick) {
    if (quick) {
        Keyboard::press(Keyboard::SHIFT);
        Mouse::click(Mouse::LEFT);
        Keyboard::release(Keyboard::SHIFT);
    } else {
        Mouse::click(Mouse::LEFT);
    }
}

void MenuCtrl::initialize(int ui_scale) {
    s_ui_scale = ui_scale;
}

void MenuCtrl::changeOffset(int offset_x, int offset_y) {
    s_inv_offset_x = offset_x * SLOT_SIZE;
    s_inv_offset_y = offset_y * SLOT_SIZE;
}
