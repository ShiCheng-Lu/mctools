#ifndef _STR_LISTENER_H_
#define _STR_LISTENER_H_

#include <string>

// NOTE: all strings are uppercase, so start must be uppercase

class StrListener {
    std::string start;
    std::string tracked;

   public:
    StrListener(std::string start);

    std::string getString(bool include_start = false);

    bool hasContent();

    void clear();

    void update();
};

#endif
