#include <iostream>
#include "circle.hh"

using namespace std;

Circle::Circle(const Point& center, double r) :
center_(center), r_(r) {}

void Circle::print(void) const {
    cout << "Circle(";
    center_.print();
    cout << ", " << r_ << ")" << endl;
}