all: draw
    
point.o: point.hh point.cc
	g++ -c point.cc

rectangle.o: rectangle.cc point.hh rectangle.hh shape.hh
	g++ --std=c++11 -c rectangle.cc

main.o: main.cc
	g++ --std=c++11 -c main.cc

circle.o: circle.cc point.hh circle.hh shape.hh
	g++ --std=c++11 -c circle.cc

drawing.o: drawing.cc drawing.hh shape.hh
	g++ --std=c++11 -c drawing.cc

draw: main.o point.o rectangle.o circle.o drawing.o
	g++ -o draw main.o point.o rectangle.o circle.o drawing.o

clean:
	rm -f *.o
	rm -f a.out
	rm -f draw