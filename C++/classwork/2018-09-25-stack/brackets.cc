#include <iostream>
#include <string>
#define STACK_SIZE 10

using namespace std;

template<class T>
class Stack {
	T data_[STACK_SIZE];
	int top_;
public:
	Stack() {
		top_ = 0;
	}

	bool empty() {
		return top_ == 0;
	}
	
	bool full() {
		return top_ == STACK_SIZE;
	}

	void push(T val) {
		if(full()) {
			cout << "OOOPPSSS!!! stack is full..." << endl;
			return;
		}
		data_[top_++] = val;
	}
	
	T pop() {
		if(empty()) {
            cout << "OOPPSS!!! stack is empty..." << endl;
            return 0;
		}
		return data_[--top_];
	}
	
	int size() {
		return top_;
	}
};

int main() {
	string str;
	cin >> str;
	Stack<char> st;
	for(string::iterator it = str.begin(); it != str.end(); it++) {
		if(*it == '(' || *it == '[' || *it == '{') {
			st.push(*it);
		}
		else if(*it == ')' || *it == ']' || *it == '}') {
			char ch = st.pop();
		}
	}
	if(st.size() == 0) {
		cout << "Balanced parenthness!" << endl;
	}
	else {
		cout << "Unbalanced parenthness!" << endl;
	}
	return 0;
}
