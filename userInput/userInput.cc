#include "userInput.h"
#include "windows.h"

InputAction::InputAction(std::vector<byte> req_keys,
                         void (*function)(void*),
                         void* context,
                         bool continuous)
    : req_keys{req_keys},
      function{function},
      context{context},
      continuous{continuous} {}

InputAction::~InputAction() {}

bool InputAction::is_active() {
    SHORT state = 0;
    for (byte key : req_keys) {
        state = GetAsyncKeyState(key);
        if (!(state & 0x8000)) {
            return false;
        }
    }
    if (continuous || (state & 1)) {
        // the action should be continuously called
        // or the action was detected and was not processed yet
        return true;
    }
    return false;
}

void InputAction::update() {
    if (is_active()) {
        function(context);
    }
}

// UserInput
UserInput::UserInput() {}
UserInput::~UserInput() {}

void UserInput::add_action(InputAction action) {
    actions.push_back(action);
}

void UserInput::start_listener() {}

void UserInput::end_listener() {}
#include <iostream>
std::string UserInput::get_typed_string(const char until) {
    // clear any queued key events
    for (byte i = 0; i < 'Z'; ++i) {
        GetAsyncKeyState(i);
    }

    BYTE kb_state[256];
    GetKeyboardState(kb_state);

    std::string result = "";
    while (true) {
        for (byte i = 0; i < 'Z'; ++i) {
            SHORT state = GetAsyncKeyState(i);
            if (!(state & 1)) {
                continue;
            }
            // key was pressed
            if (i == until) {
                return result;
            } else if (i == VK_BACK) {
                // handle for backspace char
                if (result.length() == 0) {
                    return result;
                }
                result.pop_back();
            } else {
                WORD buffer[2];
                ToAscii(i, 0, kb_state, buffer, 0);
                result.push_back(buffer[0]);
            }
        }
    }
}
