#ifndef __UNARY_HH__
#define __UNARY_HH__

#include "operation.hh"

class UnaryOperation : public Operation {
public:
    UnaryOperation(const std::string& name, Calculator& calc) :
    Operation(name, calc) {}

    void execute();

protected:
    virtual double eval(double value) = 0;
};

#endif