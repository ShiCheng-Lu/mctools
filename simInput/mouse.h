#ifndef _MOUSE_H_
#define _MOUSE_H_

class Mouse {
   public:
    enum class Button {
        LEFT,
        MIDDLE,
        RIGHT
    };
    static void click(Button but);

    static void press(Button but);
    static void release(Button but);
};

#define _MOUSE_H_
