#include <iostream>
#include "drawing.hh"

using namespace std;

void Drawing::add(const Shape * shape) {
    shapes_.push_back(shape);
}

void Drawing::print(void) const {
    cout << "Drawing {" << endl;
    for(list<const Shape *>::const_iterator it = shapes_.begin();
    it != shapes_.end(); it++) {
        (*it) -> print();
        cout << endl;
    }
    cout << "}" << endl;
}