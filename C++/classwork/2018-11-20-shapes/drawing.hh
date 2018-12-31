#ifndef __DRAWING_HH__
#define __DRAWING_HH__

#include <list>
#include "shape.hh"

using namespace std;

class Drawing {
    list<const Shape *> shapes_;
public:
    void add(const Shape * shape);
    void print(void) const;
};

#endif