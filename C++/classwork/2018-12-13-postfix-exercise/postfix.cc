#include <iostream>
#include "calculator.hh"
#include "unary.hh"
#include "negate.hh"

using namespace std;

int main() {
	Calculator calc;
	calc.add_operation(new Negate(calc));
	calc.run(cin, cout);
	return 0;
}