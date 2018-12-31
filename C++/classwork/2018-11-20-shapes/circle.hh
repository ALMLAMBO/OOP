#ifndef __CIRCLE_HH__
#define __CIRCLE_HH__

#include "point.hh"
#include "shape.hh"

class Circle : public Shape {
    Point center_;
    double r_;
public:
    Circle(const Point& center, double r);
    void print(void) const;
};

#endif