#ifndef _STR_LISTENER_H_
#define _STR_LISTENER_H_

#include <string>

class StrListener {
    std::string start;
    std::string tracked;

   public:
    StrListener(std::string start);

    std::string getString();

    bool hasContent();

    void update();
};

#endif
