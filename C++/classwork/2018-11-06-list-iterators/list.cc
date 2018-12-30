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
  friend class const_iterator;
  friend class reverse_iterator;
  friend class const_reverse_iterator;
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

  List& operator=(const List& other) {
    if(this != &other) {
      clear();
      Node * node = other.head_ -> next_;
      while(node != other.head_) {
        push_back(node -> data_);
        node = node -> next_;
      }
    }
    return *this;
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
    friend class List;
    Node * current_;
    iterator(Node * node) : current_(node) {}
  public:
    iterator() : current_(nullptr) {}

    int& operator*() {
      return current_ -> data_;
    }

    iterator& operator++() {
      current_ = current_ -> next_;
      return *this;
    }

    iterator operator++(int) {
      iterator res(current_);
      current_ = current_ -> next_;
      return res;
    }

    iterator& operator--() {
      current_ = current_ -> prev_;
      return *this;
    }

    iterator operator--(int) {
      iterator res(current_);
      current_ = current_ -> prev_;
      return res;
    }

    bool operator==(const iterator& other) const {
      return current_ == other.current_;
    }

    bool operator!=(const iterator& other) const {
      return !operator==(other);
    }
  };

  class const_iterator {
    friend class List;
    Node * current_;
    const_iterator(Node * node) : current_(node) {}
  public:
    const_iterator() : current_(nullptr) {}

    const int& operator*() {
      return current_ -> data_;
    }

    const_iterator& operator++() {
      current_ = current_ -> next_;
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator res(current_);
      current_ = current_ -> next_;
      return res;
    }

    const_iterator& operator--() {
      current_ = current_ -> prev_;
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator res(current_);
      current_ = current_ -> prev_;
      return res;
    }

    bool operator==(const const_iterator& other) const {
      return current_ == other.current_;
    }

    bool operator!=(const const_iterator& other) const {
      return !operator==(other);
    }
  };

  class reverse_iterator {
    friend class List;
    Node * current_;
    reverse_iterator(Node * node) : current_(node -> prev_) {}
  public:
    reverse_iterator() : current_(nullptr) {}

    int& operator*() {
      return current_ -> data_;
    }

    reverse_iterator& operator++() {
      current_ = current_ -> prev_;
      return *this;
    }

    reverse_iterator operator++(int) {
      reverse_iterator res(current_);
      current_ = current_ -> prev_;
      return res;
    }

    reverse_iterator& operator--() {
      current_ = current_ -> next_;
      return *this;
    }

    reverse_iterator operator--(int) {
      reverse_iterator res(current_);
      current_ = current_ -> next_;
      return res;
    }

    bool operator==(const reverse_iterator& other) const {
      return current_ == other.current_;
    }

    bool operator!=(const reverse_iterator& other) const {
      return !operator==(other);
    }
  };

  class const_reverse_iterator {
    friend class List;
    Node * current_;
    const_reverse_iterator(Node * node) : current_(node -> prev_) {}
  public:
    const_reverse_iterator() : current_(nullptr) {}

    int& operator*() {
      return current_ -> data_;
    }

    const_reverse_iterator& operator++() {
      current_ = current_ -> prev_;
      return *this;
    }

    const_reverse_iterator operator++(int) {
      const_reverse_iterator res(current_);
      current_ = current_ -> prev_;
      return res;
    }

    const_reverse_iterator& operator--() {
      current_ = current_ -> next_;
      return *this;
    }

    const_reverse_iterator operator--(int) {
      const_reverse_iterator res(current_);
      current_ = current_ -> next_;
      return res;
    }

    bool operator==(const const_reverse_iterator& other) const {
      return current_ == other.current_;
    }

    bool operator!=(const const_reverse_iterator& other) const {
      return !operator==(other);
    }
  };

  iterator insert(iterator it, int value) {
    Node * node = new Node(value);
    Node * prev = it.current_ -> prev_;
    node -> next_ = it.current_;
    it.current_ -> prev_ = node;
    prev -> next_ = node;
    node -> prev_ = prev;
    return iterator();
  }

  iterator erase(iterator it) {
    if(empty()) {
      throw ListException("Try to erase element on an empty list");
    }
    if(it.current_ == this -> head_) {
      throw ListException("Try to erase the head of the list");
    }
    Node * node = it.current_;
    Node * prev = it.current_ -> prev_;
    Node * next = it.current_ -> next_;
    prev -> next_ = next;
    next -> prev_ = prev;
    delete it.current_;
    return iterator();
  }

  iterator erase(iterator first, iterator last) {
    while(first != last) {
      erase(first);
      first++;
    }
    return iterator();
  }

  iterator begin() {
    return iterator(head_ -> next_);
  }

  iterator end() {
    return iterator(head_);
  }

  const_iterator cbegin() {
    return const_iterator(head_ -> next_);
  }

  const_iterator cend() {
    return const_iterator(head_);
  }

  reverse_iterator rbegin() {
    return reverse_iterator(head_);
  }

  reverse_iterator rend() {
    return reverse_iterator(head_ -> next_);
  }

  const_reverse_iterator crbegin() {
    return const_reverse_iterator(head_);
  }

  const_reverse_iterator crend() {
    return const_reverse_iterator(head_ -> next_);
  }

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
};

int main() {
  try{
      List l1;
      for (int i = 0; i < 10; i++) {
        l1.push_front(i * 2);
      }
      cout << "Normal iterator" << endl;
      for(List::iterator it = l1.begin(); it != l1.end(); it++) {
        cout << "element = " << *it << endl;
      }
      cout << "Const iterator" << endl;
      for(List::const_iterator it = l1.cbegin();it != l1.cend(); it++) {
        cout << "element = " << *it << endl;
      }
      cout << "Reverse iterator" << endl;
      for(List::reverse_iterator it = l1.rbegin(); it != l1.rend(); it++) {
        cout << "element = " << *it << endl;
      }
      cout << "Const reverse iterator" << endl;
      for(List::const_reverse_iterator it = l1.crbegin(); it != l1.crend(); it++) {
        cout << "element = " << *it << endl;
      }
      cout << "Insert method" << endl;
      List::iterator it1 = l1.begin();
      List::iterator it2 = l1.insert(it1, 20);
      for(List::iterator it = l1.begin(); it != l1.end(); it++) {
        cout << "element = " << *it << endl;
      }
      cout << endl << endl << "Erase method" << endl;
      List::iterator it3 = l1.begin();
      List::iterator lt4 = l1.erase(it3);
      for(List::iterator it = l1.begin(); it != l1.end(); it++) {
        cout << "element = " << *it << endl;
      }
      cout << endl << "Erase range of elements" << endl;
      List::iterator it5 = l1.erase(l1.begin(), l1.end());
      for(List::iterator it = l1.begin(); it != l1.end(); it++) {
        cout << "element = " << *it << endl;
      }
  }
  catch(ListException e) {
    cout << "ERR: " << e.get_message() << endl;
  }
  return 0;
}
