all: postfix

calculator.o: calculator.hh calculator.cc

unary.o: unary.cc unary.hh operation.hh

negate.o: negate.cc negate.hh unary.hh operation.hh

postfix.o: postfix.cc calculator.hh

postfix: calculator.o postfix.o unary.o negate.o
	g++ -o postfix postfix.o calculator.o unary.o negate.o

clean:
	rm -f *.o
	rm -f a.out
	rm -f postfix
