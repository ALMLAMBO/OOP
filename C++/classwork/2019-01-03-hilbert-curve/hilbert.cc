#include <iostream>
#include "turtle.hh"

using namespace std;

class Hilbert {
    Turtle &turtle_;
    double step_;

public:

    Hilbert(Turtle &turtle) :
    turtle_(turtle), step_(20) {}

    void draw_a(int order) {
        if(order <= 0) {
            return;
        }
        draw_d(order - 1);
        turtle_.set_heading(180).forward(step_);
        draw_a(order - 1);
        turtle_.set_heading(-90).forward(step_);
        draw_a(order - 1);
        turtle_.set_heading(0).forward(step_);
        draw_b(order - 1);
    }
    
    void draw_b(int order) {
        if(order <= 0) {
            return;
        }

    }
    
    void draw_c(int order) {
        if(order <= 0) {
            return;
        }
    }
    
    void draw_d(int order) {
        if(order <= 0) {
            return;
        }
    }
};

int main() {
    PSTurtle t = PSTurtle(200, 200);
    t.setup()
            .pensize(2)
			.moveto(Point(100, 200))
			.set_heading(0)
            .forward(20)
            .set_heading(90)
            .forward(20)
            .set_heading(180)
            .forward(20);
    Hilbert h(t);
    return 0;
}