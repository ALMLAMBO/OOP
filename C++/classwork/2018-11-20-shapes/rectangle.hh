#ifndef __RECTANGLE_HH__
#define __RECTANGLE_HH__
#include "point.hh"
#include "shape.hh"

class Rectangle : public Shape{
    Point ul_;
    Point br_;
public:
    Rectangle(const Point& ul, const Point& br);

    const Point& get_ul() const {
        return ul_;
    }

    const Point& get_br() const {
        return br_;
    }

    void print(void) const;
};

#endif