#ifndef CALCULATOR_HH_
#define CALCULATOR_HH_

#include <iostream>
#include <stack>
#include <list>
#include <string>

class Operation;

class Calculator {
	std::stack<double> values_;
	std::list<Operation*> operations_;

public:
	void push(double value);
	double pop();
	void run(std::istream& in, std::ostream& out);
	Operation* get_operation(std::string name) const;
	void add_operation(Operation* operation);
};

#endif
