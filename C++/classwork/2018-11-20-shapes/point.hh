#ifndef __POINT_HH__
#define __POINT_HH__

class Point {
    double x_, y_;
public:
    Point(double x = 0.0, double y = 0.0) :
    x_(x), y_(y) {}

    Point& set_x(double x) {
        x_ = x;
        return *this;
    }

    Point& set_y(double y) {
        y_ = y;
        return *this;
    }

    double get_x() const {
        return x_;
    }

    double get_Y() const {
        return y_;
    }

    void print(void) const;
};

#endif