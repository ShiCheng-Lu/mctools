#include <windows.h>
#include <iostream>
#include <vector>
#include "actionController.h"
#include "movementController.h"

void endloop(void* flag) {
    *(bool*)flag = false;
}

void takeAll(void* ac) {
    keybd_event(VK_SHIFT, 0, 0, 0);
    ((ActionController*)ac)->forallInv(takeItem);
    keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
    
}

int main(int argc, char* argv[]) {
    std::cout << "ready" << std::endl;
    bool loop = true;
    std::vector<byte> keys{VK_ESCAPE};
    InputAction ia{keys, endloop, &loop};

    ActionController ac;
    ac.setInvType(ActionController::InvType::Chest);
    std::vector<byte> keys2{VK_CONTROL, 'R'};
    InputAction ia2{keys2, takeAll, &ac};

    while (loop) {
        ia.update();
        ia2.update();
    }
}
