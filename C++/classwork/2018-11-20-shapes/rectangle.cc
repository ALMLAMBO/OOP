#include <iostream>
#include "rectangle.hh"

using namespace std;

Rectangle::Rectangle(const Point& ul, const Point& br) :
ul_(ul), br_(br) {}

void Rectangle::print(void) const {
    cout << "Rectngle(";
    ul_.print();
    cout << ", ";
    br_.print();
    cout << ")" << endl;
}