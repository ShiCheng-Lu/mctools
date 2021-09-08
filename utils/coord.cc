#include "coord.h"

// Point

Point Point::operator/(const int& a) {
    return Point{x / a, y / a};
}

Point Point::operator+(const Point& other) {
    return Point{x + other.x, y + other.y};
}


std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << p.x << ',' << p.y;
    return out;
}

// Coord

std::ostream& operator<<(std::ostream& out, const Coord& p) {
    out << p.x << ',' << p.y << ',' << p.z;
    return out;
}

// Rect

std::ostream& operator<<(std::ostream& out, const Rect& p) {
    out << p.left << ',' << p.top << ',' << p.right << ',' << p.bottom;
    return out;
}
