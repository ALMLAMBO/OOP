#ifndef __NEGATE_HH__
#define __NEGATE_HH__

#include "unary.hh"

class Negate : public UnaryOperation {
public:
    Negate(Calculator& calc) :
    UnaryOperation("neg", calc) {}

    double eval(double value);
};

#endif