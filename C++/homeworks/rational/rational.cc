#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
problem description: 
https://www.hackerrank.com/contests/rationals-1-1/challenges/rationals-calculator
*/

class RationalException {
    string message_;
public:
    RationalException(string message) :
    message_(message) {}

    string get_message() {
        return message_;
    }
};

class Rational {
    long num_, den_;

    long gcd(long num, long den) {
        if(num < 0) {
            num = -num;
        }
        long r = num % den;
        while(r != 0) {
            num = den;
            den = r;
            r = num % den;
        }
        return den;
    }

    void reduce() {
        long r = gcd(num_, den_);
        num_ /= r;
        den_ /= r;
    }

    void standartize() {
        if(den_ < 0) {
            num_ = -num_;
            den_ = -den_;
            reduce();
        }
        if(num_ < 0) {
            reduce();
        }
        if(num_ == 0) {
            den_ = 1;
        }
        else {
            reduce();
        }
    }

public:
    Rational(long num, long den) {
        if(den == 0) {
            throw RationalException("YOU CANNOT HAVE DENOMINATOR 0");
        }
        num_ = num;
        den_ = den;
        standartize();
    }

    ~Rational() {
        num_ = 0;
        den_ = 1;
    }

    Rational& set_num(long num) {
        num_ = num;
        return *this;
    }

    Rational& set_den(long den) {
        den_ = den;
        return *this;
    }

    long get_num() const {
        return num_;
    }

    long get_den() const {
        return den_;
    }

    void print() {
        cout << "(" << num_ << "/" << den_ << ")" << endl;
    }

    Rational& operator+(Rational& other) {
        reduce();
        other.reduce();
        set_num(get_num() * other.get_den() + get_den() * other.get_num());
        set_den(get_den() * other.get_den());
        standartize();
        return *this;
    }

    Rational& operator-(Rational& other) {
        reduce();
        other.reduce();
        set_num(get_num() * other.get_den() - get_den() * other.get_num());
        set_den(get_den() * other.get_den());
        standartize();
        return *this;
    }

    Rational& operator*(Rational& other) {
        reduce();
        other.reduce();
        set_num(get_num() * other.get_num());
        set_den(get_den() * other.get_den());
        standartize();
        return *this;
    }

    Rational& operator/(Rational& other) {
        reduce();
        other.reduce();
        if(get_den() == 0 || other.get_num() == 0) {
            throw RationalException("YOU CANNOT HAVE DENOMINATOR 0");
        }
        set_num(get_num() * other.get_den());
        set_den(get_den() * other.get_num());
        standartize();
        return *this;
    }
    
    Rational& operator=(Rational& other) {
        num_ = other.num_;
        den_ = other.den_;
        return *this;
    }
};

istream& operator>>(istream& in, Rational& rational);
ostream& operator<<(ostream& out, list<Rational>& result);
list<Rational> calcFractions(list<Rational> fractions, list<char> signs);
bool isSign(char ch);

int main() {
    try {
        list<Rational> fractions;
        list<char> signs;
        list<Rational> result;
        char sign;
        while(true) {
            Rational r(0, 1);
            cin >> r;
            if(cin.fail()) {
                break;
            }
            cin >> skipws >> sign;
            fractions.push_back(r);
            if(isSign(sign)) {
                signs.push_back(sign);
            }
        }
        result = calcFractions(fractions, signs);
        cout << result;
    }
    catch(RationalException e) {
        cout << "ERR: " << e.get_message() << endl;
    }
    return 0;
}

istream& operator>>(istream& in, Rational& rational) {
    long num, den;
    char ch;
    in >> ch;
    if(ch != '(') {
        in.clear(ios_base::badbit);
    }
    if(ch == 'q') {
        return in;
    }
    in >> num >> ch;
    if(ch != '/') {
        in.clear(ios_base::badbit);
    }
    in >> den >> ch;
    if(ch != ')') {
        in.clear(ios_base::badbit);
    }
    rational.set_num(num);
    rational.set_den(den);
    return in;
}

ostream& operator<<(ostream& out, list<Rational>& result) {
    for(list<Rational>::iterator it = result.begin();
    it != result.end(); it++) {
        cout << "> ";
        Rational r(0, 1);
        r = *it;
        r.print();
    }
    cout << ">" << endl;
    return out;
}

list<Rational> calcFractions(list<Rational> fractions, list<char> signs) {
    list<Rational> result;
    Rational r1(0, 1);
    Rational r2(0, 1);
    r1 = fractions.front();
    fractions.pop_front();
    while(true) {
        char sign = signs.front();
        if (sign == '=') {
        result.push_back(r1);
        r1.~Rational();
        r2.~Rational();
        if (!fractions.empty()) {
                r1 = fractions.front();
                fractions.pop_front();
            }
        }
        else {
            if (!fractions.empty()) {
                r2 = fractions.front();
                fractions.pop_front();
            }
            switch (sign) {
            case '+':
                r1.operator+(r2);
                break;
            case '-':
                r1.operator-(r2);
                break;
            case '*':
                r1.operator*(r2);
                break;
            case '/':
                r1.operator/(r2);
                break;
            }
        }
        signs.pop_front();
        if (fractions.empty() && signs.empty()) {
            break;
        }
    }
    return result;
}

bool isSign(char ch) {
    return ch == '+' || ch == '-' ||
    ch == '*' || ch == '/' || ch == '=';
}