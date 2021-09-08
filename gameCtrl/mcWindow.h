#ifndef _MC_WINDOW_H_
#define _MC_WINDOW_H_

// defines the mc window

#include "../utils/coord.h"

class McWindow {
    int ui_size;
    Rect rect;

    Point center;

    int width, height;

   public:
    McWindow();

    Point getTopLeft() const;

    Point getCenter() const;

    Point ui_scale(const Point& p) const;

    void update();
};

#endif
