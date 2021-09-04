#ifndef _USER_INPUT_H_
#define _USER_INPUT_H_

#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <bitset>

#define VK_SLASH VK_OEM_2

#define KEY_MAX 0xFF

typedef unsigned char byte;

class KeyboardTracker {
    static std::bitset<KEY_MAX> down;
    static std::bitset<KEY_MAX> pressed;
   public:
    static void update();
    static void isDown(byte key);
    static void isPressed(byte key);
};

class InputAction {
    std::vector<byte> req_keys;
    void (*function)(void*);
    void* context;
    bool activated;
    bool continuous;

   public:
    InputAction(std::vector<byte> req_keys,
                void (*function)(void*),
                void* context = nullptr,
                bool continuous = false);
    ~InputAction();

    bool is_active();
    void update();
};

class UserInput {
    std::vector<InputAction> actions;

   public:
    UserInput();
    ~UserInput();

    void add_action(InputAction action);

    void start_listener();

    void end_listener();

    // get typed string from the user until the arg character is inputted
    std::string get_typed_string(const char until = '\r');
};

#endif
