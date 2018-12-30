#include <iostream>
#include <string>

using namespace std;

class ListException {
  string message_;
public:
  ListException(string message) :
  message_(message) {}

  string get_message() {
    return message_;
  }
};

class List {
  struct Node {
    int data_;
    Node * next_;
    Node * prev_;
    Node(int data) :
    data_(data), next_(nullptr), prev_(nullptr) {}
  };

  Node * head_;
  friend class iterator;
public:
  List() : head_(new Node(0)) {
    head_ -> next_ = head_;
    head_ -> prev_ = head_;
  }

  List(const List& other) : head_(new Node(0)){
    head_ -> next_ = head_;
    head_ -> prev_ = head_;
    Node * node = other.head_ -> next_;
    while(node != other.head_) {
      push_back(node -> data_);
      node = node -> next_;
    }
  }

  ~List() {
    while(!empty()) {
      pop_back();
    }
    delete head_;
  }

  bool empty() const {
    return head_ -> next_ == head_;
  }

  void push_front(int value) {
    Node * front = head_ -> next_;
    Node * node = new Node(value);
    head_ -> next_ = node;
    node -> prev_ = head_;
    front -> prev_ = node;
    node -> next_ = front;
  }

  void push_back(int value) {
    Node * back = head_ -> prev_;
    Node * node = new Node(value);
    back -> next_ = node;
    node -> prev_ = back;
    head_ -> prev_ = node;
    node -> next_ = head_;
  }

  void pop_front() {
    if(empty()) {
      throw ListException("Try to pop on an empty list");
    }
    Node * front = head_ -> next_;
    Node * new_front = front -> next_;
    head_ -> next_ = new_front;
    new_front -> prev_ = head_;
    delete front;
  }

  void pop_back() {
    if(empty()) {
      throw ListException("Try to pop on an empty list");
    }
    Node * back = head_ -> prev_;
    Node * new_back = back -> prev_;
    new_back -> next_ = head_;
    head_ -> prev_ = new_back;
    delete back;
  }

  int size() {
    int size = 0;
    while(!empty()) {
      pop_back();
      size++;
    }
    return size;
  }

  void clear() {
    while(!empty()) {
      pop_back();
    }
  }

  class iterator {
    Node * current_;
  };

  int front() const {
    if(empty()) {
      throw ListException("Called front() on an empty list");
    }
    return head_ -> next_ -> data_;
  }

  int back() const {
    if(empty()) {
      throw ListException("Called back() on an empty list");
    }
    return head_ -> prev_ -> data_;
  }

  /*const int front() const {
    if(empty()) {
      throw ListException("Called front() on an empty list");
    }
    return head_ -> next_ -> data_;
  }*/

  /*const int back() const {
    if(empty()) {
      throw ListException("Called back() on an empty list");
    }
    return head_ -> prev_ -> data_;
  }*/
};

int main() {
  List l1;
  for (int i = 0; i < 10; i++) {
    l1.push_front(i * 2);
  }
  cout << l1.size() << endl;
  l1.clear();
  cout << l1.size() << endl;
  return 0;
}
