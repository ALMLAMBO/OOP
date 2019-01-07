#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

/*
problem description:
https://www.hackerrank.com/contests/minesweeper-elsys-4th-homework/challenges/minesweeper-cmd-elsys
*/

class Exception {
    string message_;
public:
    Exception(string message) :
    message_(message) {}

    string get_message() const {
        return message_;
    }
};

class point {
    int x_, y_;
public:
    point(int x = 0, int y = 0) :
    x_(x), y_(y) {}

    int get_x() const {
        return x_;
    }

    int get_y() const {
        return y_;
    }

    void set_x(int x) {
        x_ = x;
    }

    void set_y(int y) {
        y_ = y;
    }
};

class bomb : public point {
    int flag_;
    char symbol_;
public:
    bomb() :flag_(0), symbol_('_') {}

    bool operator==(const bomb& other) const {
        return get_x() == other.get_x() && 
        get_y() == other.get_y();
    }

    bomb& set_flag(int flag) {
        flag_ = flag;
        return *this;
    }

    bomb& set_symbol(char symbol) {
        symbol_ = symbol;
        return *this;
    }

    char get_symbol() const {
        return symbol_;
    }

    int get_flag() const {
        return flag_;
    }
};

istream& operator>>(istream& in, point& p) {
    int x, y;
    char c;
    in >> x >> c;
    if(c != ',') {
        in.clear(ios_base::badbit);
    }
    in >> y;
    p.set_x(x);
    p.set_y(y);
    return in;
}

template<typename T>
T ** init(int width, int height) {
    T ** board = new T*[height];
    for(int i = 0; i < height; i++) {
        board[i] = new T[width];
    }
    return board;
}

template<typename T>
void destroy(T ** &board, int width, int height) {
    for(int i = 0; i < height; i++) {
        delete [] board[i];
    }
    delete [] board;
}

class board {
public:
    virtual void draw_board(char ** &board) = 0;
    virtual void init_real_board(bomb ** board, 
    vector<point> bombs) = 0;
};

class minesweeper : public bomb {
    int width_, height_;
    vector<point> bombs_;
    istream& in_;
    ostream& out_;
    char ** field_;
    bomb ** realBoard_;

public:
    minesweeper(int width, int height
    , const vector<point>& bombs, istream& in, ostream& out) :
    width_(width), height_(height), bombs_(bombs), in_(in)
    , out_(out) {
        field_ = init<char>(width_, height_);
        realBoard_ = init<bomb>(width_, height_);
        for(int i = 0; i < height_; i++) {
            for(int j = 0; j < width_; j++) {
                field_[i][j] = '_';
            }
        }
    }
    
    void run() {
        draw_board(field_);
        destroy<char>(field_, width_, height_);
        destroy<bomb>(realBoard_, width_, height_);
    }

    void draw_board(char ** &board) {
        for(int i = 0; i < height_; i++) {
            for(int j = 0; j < width_; j++) {
                out_ << board[i][j];
            }
            out_ << endl;
        }
        out_ << "> ";
    }

    void init_real_board(bomb ** readBoard, vector<point> bombs) {
        
    }
};

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    int width, height;
    iss >> width >> height;
    getline(cin, line);
    iss.str(line);
    iss.clear();
    int bombs_count;
    iss >> bombs_count;
    vector<point> bombs;
    for(int i = 0; i < bombs_count; i++) {
        point p;
        getline(cin, line);
        iss.str(line);
        iss.clear();
        iss >> p;
        bombs.push_back(p);
    }
    minesweeper game(width, height, bombs, cin, cout);
    game.run();
    return 0;
}