#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class StringException {
  string message_;
public:
  StringException(string message) :
  message_(message) {}

  string get_message() {
    return message_;
  }
};

class String {
  int size_;
  int capacity_;
  char * data_;

  void resize() {
    if(size_ == capacity_) {
      capacity_ *= 2;
    }
    char * new_data = new char[capacity_];
    for(int i = 0; i < size_; i++) {
      new_data[i] = data_[i];
    }
    delete []data_;
    data_ = new_data;
  }
  friend class iterator;
  friend class const_iterator;
  friend class reverse_iterator;
  friend class const_reverse_iterator;
public:

  String(int capacity) : size_(0), capacity_(capacity),
  data_(new char[capacity_]) {}

  String(const char * str) : size_(strlen(str)),
  capacity_(size_ + 1), data_(new char[capacity_]) {
    strcpy(data_, str);
  }

  ~String() {
    delete []data_;
    size_ = 0;
    capacity_ = 0;
  }

  String(const String& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = new char[capacity_];
    strcpy(data_, other.data_);
  }

  int size() const {
    return size_;
  }

  int lenght() const {
    return strlen(data_);
  }

  int capacity() const {
    return capacity_;
  }

  bool empty() const {
    return size_ == 0;
  }

  void clear() {
    delete []data_;
  }

  char& operator[](int index) const {
    return data_[index];
  }

  char& at(int index) const {
    return data_[index];
  }

  bool operator==(const String& other) {
    return strcmp(data_, other.data_) == 0;
  }

  bool operator!=(const String& other) {
    return strcmp(data_, other.data_) != 0;
  }

  bool operator<(const String& other) {
    return strcmp(data_, other.data_) < 0;
  }

  bool operator>(const String& other) {
    return strcmp(data_, other.data_) > 0;
  }

  bool operator<=(const String& other) {
    return strcmp(data_, other.data_) <= 0;
  }

  bool operator>=(const String& other) {
    return strcmp(data_, other.data_) >= 0;
  }

  String& operator=(const String& other) {
    capacity_ = other.capacity_;
    delete []data_;
    data_ = new char[capacity_];
    size_ = other.size_;
    strcpy(data_, other.data_);
  }

  String& append(const String& other) {
    if(size_ == capacity_) {
      resize();
    }
    data_ = strcat(data_, other.data_);
    return *this;
  }

  String& operator+=(const String& other) {
    if(size_ == capacity_) {
      resize();
    }
    data_ = strcat(data_, other.data_);
    return *this;
  }

  String operator+(const String& other) {
    String result((capacity_ + other.capacity_) + 1);
    result.data_ = strcat(data_, other.data_);
    return result;
  }

  void push_back(char ch) {
    if(size_ == capacity_) {
      resize();
    }
    data_[size_] = ch;
    size_++;
  }

  unsigned find(const String& other, unsigned pos) {

  }

  unsigned find_first_of(const String& other, unsigned pos) {

  }

  String substr(unsigned begin, unsigned end) {
    if(begin < 0 || end > size_) {
      throw StringException("Use unallowed memory");
    }
    String result((end - begin) + 1);
    for(unsigned i = begin; i <= end; i++) {
      result.push_back(data_[i]);
    }
    return result;
  }

  class iterator {
    int index_;
    String * str_;
    iterator(int index) : index_(index) {}
    friend class String;
  public:
    iterator() : index_(0) {}
    iterator(int index, String * str) :
    index_(index), str_(str) {}

    char& operator*() {
      return str_ -> data_[index_];
    }

    iterator& operator++() {
      index_++;
      return *this;
    }

    iterator operator++(int) {
      iterator res(index_);
      index_++;
      return res;
    }

    iterator& operator--() {
      index_--;
      return *this;
    }

    iterator operator--(int) {
      iterator res(index_);
      index_--;
      return res;
    }

    bool operator==(const iterator& other) const {
      return index_ == other.index_;
    }

    bool operator!=(const iterator& other) const {
      return !operator==(other);
    }
  };

  class const_iterator {
    int index_;
    String * str_;
    const_iterator(int index) : index_(index) {}
    friend class String;
  public:
    const_iterator() : index_(0) {}
    const_iterator(int index, String * str) :
    index_(index), str_(str) {}

    const char& operator*() {
      return str_ -> data_[index_];
    }

    const_iterator& operator++() {
      index_++;
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator res(index_);
      index_++;
      return res;
    }

    const_iterator& operator--() {
      index_--;
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator res(index_);
      index_--;
      return res;
    }

    bool operator==(const const_iterator& other) const {
      return index_ == other.index_;
    }

    bool operator!=(const const_iterator& other) const {
      return !operator==(other);
    }
  };

  class reverse_iterator {
    int index_;
    String * str_;
    reverse_iterator(int index) : index_(index) {}
    friend class String;
  public:
    reverse_iterator() : index_(0) {}
    reverse_iterator(int index, String * str) :
    index_(index - 1), str_(str) {}

    char& operator*() {
      return str_ -> data_[index_];
    }

    reverse_iterator& operator++() {
      index_--;
      return *this;
    }

    reverse_iterator operator++(int) {
      reverse_iterator res(index_);
      index_--;
      return res;
    }

    reverse_iterator& operator--() {
      index_++;
      return *this;
    }

    reverse_iterator operator--(int) {
      reverse_iterator res(index_);
      index_++;
      return res;
    }

    bool operator==(const reverse_iterator& other) const {
      return index_ == other.index_;
    }

    bool operator!=(const reverse_iterator& other) const {
      return !operator==(other);
    }
  };

  class const_reverse_iterator {
    int index_;
    String * str_;
    const_reverse_iterator(int index) : index_(index) {}
    friend class String;
  public:
    const_reverse_iterator() : index_(0) {}
    const_reverse_iterator(int index, String * str) :
    index_(index - 1), str_(str) {}

    const char& operator*() {
      return str_ -> data_[index_];
    }

    const_reverse_iterator& operator++() {
      index_--;
      return *this;
    }

    const_reverse_iterator operator++(int) {
      const_reverse_iterator res(index_);
      index_--;
      return res;
    }

    const_reverse_iterator& operator--() {
      index_++;
      return *this;
    }

    const_reverse_iterator operator--(int) {
      const_reverse_iterator res(index_);
      index_++;
      return res;
    }

    bool operator==(const const_reverse_iterator& other) const {
      return index_ == other.index_;
    }

    bool operator!=(const const_reverse_iterator& other) const {
      return !operator==(other);
    }
  };

  iterator begin() {
    return iterator(0, this);
  }

  iterator end() {
    return iterator(size_, this);
  }

  const_iterator cbegin() {
    return const_iterator(0, this);
  }

  const_iterator cend() {
    return const_iterator(size_, this);
  }

  reverse_iterator rbegin() {
    return reverse_iterator(size_, this);
  }

  reverse_iterator rend() {
    return reverse_iterator(0, this);
  }

  const_reverse_iterator crbegin() {
    return const_reverse_iterator(size_, this);
  }

  const_reverse_iterator crend() {
    return const_reverse_iterator(0, this);
  }
};

ostream& operator<<(ostream& out, const String& other) {
  for(int i = 0; i < other.size(); i++) {
    cout << other[i];
  }
  cout << endl;
  return out;
}

int main() {
  String str1("this is a string");
  String str2(str1);
  /*cout << str1;
  cout << str2;
  cout << str1[3] << endl;
  cout << str2.at(12) << endl;
  cout << str1.size() << endl;
  int b1 = str1 >= str2;
  cout << b1 << endl;
  String str3 = str1;
  cout << str3;*/
  cout << "Normal iterator" << endl;
  for(String::iterator it = str1.begin(); it != str1.end(); it++) {
    cout << *it;
  }
  cout << endl << endl;
  cout << "Const iterator" << endl;
  for(String::const_iterator it = str1.cbegin(); it != str1.cend(); it++) {
    cout << *it;
  }
  cout << endl << endl;
  cout << "Reverse iterator" << endl;
  for(String::reverse_iterator it = str1.rbegin(); it != str1.rend(); it++) {
    cout << *it;
  }
  cout << endl << endl;
  cout << "Const reverse iterator" << endl;
  for(String::const_reverse_iterator it = str1.crbegin(); it != str1.crend(); it++) {
    cout << *it;
  }
  cout << endl;
  String str4 = str1.substr(3, 5);
  cout << endl << str4;
  return 0;
}
