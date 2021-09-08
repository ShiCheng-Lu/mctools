#ifndef _COORD_H_
#define _COORD_H_

#include <iostream>

class Point {
   public:
    int x, y;

    Point operator/(int a);
};

std::ostream& operator<<(std::ostream& out, const Point p);

class Coord {
   public:
    int x, y, z;
};

std::ostream& operator<<(std::ostream& out, const Coord p);

class Rect {
   public:
    int left, top, right, bottom;
};

std::ostream& operator<<(std::ostream& out, const Rect p);

#endif
