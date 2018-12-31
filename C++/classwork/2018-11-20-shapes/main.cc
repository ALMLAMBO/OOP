#include "drawing.hh"
#include "rectangle.hh"
#include "circle.hh"
#include "point.hh"

int main() {
    Point p1(1, 2);
    Point p2(2, 4);
    p1.print();
    p2.print();
    Rectangle r(p1, p2);
    r.print();
    return 0;
}