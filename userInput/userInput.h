#ifndef _USER_INPUT_H_
#define _USER_INPUT_H_

#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <bitset>

#define VK_SLASH VK_OEM_2

#define KEY_MAX 0xFF

#include <cstdint>

class InputAction {
    std::vector<uint8_t> req_keys;
    void (*function)(void*);
    void* context;
    bool activated;
    bool continuous;

   public:
    InputAction(std::vector<uint8_t> req_keys,
                void (*function)(void*),
                void* context = nullptr,
                bool continuous = false);
    ~InputAction();

    bool is_active();
    void update();
};

class Dispatcher {
    std::vector<InputAction> actions;

   public:
    Dispatcher();
    ~Dispatcher();

    void add_action(InputAction action);

    void start_listener();

    void end_listener();

    // get typed string from the user until the arg character is inputted
    std::string get_typed_string(const char until = '\r');
};

#endif
