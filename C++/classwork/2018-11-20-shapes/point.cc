#include <iostream>
#include "point.hh"

using namespace std;

void Point::print(void) const {
     cout << "(" << x_ << ", " << y_ << ")" << endl;
}