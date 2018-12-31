#include <iostream>
#include <string>

using namespace std;

class Employee {
    int id_;
    string name_;

protected:
    int pv_;

public:

    Employee(int id, string name) :
    id_(id), name_(name) {}

    int get_id() const {
        return id_;
    }

    const string& get_name() const {
        return name_;
    } 

    void print() const {
        cout << "name: " << name_ << "; " << "id: " << id_ << endl;
    }
};

class Manager : public Employee{
    int level_;

public:
    
    Manager(int id, string name, int level) : 
    Employee(id, name), level_(level) {}

    int get_level() const {
        return level_;
    }

    void print() const {
        //Employee::print();
        cout << "name: " << get_name() << "; " << "id: " << get_id() 
        << " shef level: " << level_ << endl;
        // cout << pv_ << endl;
    }
};

void foo(const Employee& e) {
    e.print();
}

int main() {
    Employee e1(1, "ivan");
    Employee e2(2, "peshe");
    Manager m1(100, "shef", 1);
    e1.print();
    e2.print();
    m1.print();
    cout << m1.get_id() << " ";
    cout << m1.get_name() << " ";
    cout << m1.get_level() << endl;
    Employee em = m1;
    cout << endl << endl << endl;
    foo(e1);
    foo(m1);
    return 0;
}