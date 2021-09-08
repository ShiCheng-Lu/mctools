#include "coord.h"

Point Point::operator/(int a) {
    return Point{x / a, y / a};
}

std::ostream& operator<<(std::ostream& out, const Point p) {
    out << p.x << ',' << p.y;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Coord p) {
    out << p.x << ',' << p.y << ',' << p.z;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Rect p) {
    out << p.left << ',' << p.top << ',' << p.right << ',' << p.bottom;
    return out;
}
