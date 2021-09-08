#include "strListener.h"

#include "utils/keyboard.h"

const std::string specialChars{"/\r"};

StrListener::StrListener(std::string start) : start{start} {}

std::string StrListener::getString(bool include_start) {
    if (include_start) {
        return tracked;
    }
    if (hasContent()) {
        return tracked.substr(start.size());
    } else {
        return "";
    }
}

bool StrListener::hasContent() {
    // if tracked starts with |start|
    return tracked.rfind(start, 0) == 0;
}

void StrListener::clear() {
    tracked = "";
}

void StrListener::update() {
    if (tracked.size() == 0 && !Keyboard::isPressed(start[0])) {
        return;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (Keyboard::isPressed(c)) {
            tracked += c;
        }
    }

    // backspace is pressed, delete a character
    if (Keyboard::isPressed('\b')) {
        tracked.pop_back();
    }

    for (char c : specialChars) {
        if (Keyboard::isPressed(c)) {
            tracked += c;
        }
    }
}