#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/*
problem description:
https://www.hackerrank.com/contests/third-homework/challenges/list-of-arrays
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

class ListOfArrays {
    class ArrayNode {
    public:

        int * data_;
        int size_;
        ArrayNode * prev_;
        ArrayNode * next_;

        ArrayNode(int * data, int size)
        : data_(data), size_(size), next_(0), prev_(0) {}

        ~ArrayNode() {
            delete [] data_;
        }
    };

    ArrayNode * head_;
    int size_;

    void pop() {
        if(empty()) {
            throw Exception("Try to pop on empty list");
        }
        ArrayNode * back = head_ -> prev_;
        ArrayNode * new_back = back -> prev_;
        new_back -> next_ = head_;
        head_ -> prev_ = new_back;
        delete back;
        size_--;
    }

    bool empty() const {
        return size_ == 0;
    }

    void clear() {
        while(!empty()) {
            pop();
        }
    }

public:
    class Iterator {
        friend class ListOfArrays;
        ListOfArrays& list_;
        ArrayNode * current_;

    public:

        Iterator(ListOfArrays& list, ArrayNode* current)
        : list_(list), current_(current) {}

        bool operator==(const Iterator& other) {
            return current_ == other.current_;
        }

        bool operator!=(const Iterator& other) {
            return !operator==(other);
        }

        Iterator& operator++() {
            current_ = current_ -> next_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator it(list_, current_);
            current_ = current_ -> next_;
            return it;
        }

        int& operator[](const int& index) {
            return current_ -> data_[index];
        }

        int size() {
            return current_ -> size_;
        }

        void show() {
            for(int i = 0; i < current_ -> size_; i++) {
                if(current_ -> data_[i] != 0) {
                    cout << current_ -> data_[i];
                }
                if(i != current_ -> size_ - 1) {
                    cout << " ";
                }
            }
        }
        
        double average() {
            return sum() / current_ -> size_;
        }
        
        double median() {
            int index = current_ -> size_ / 2;
            if(index % 2 == 0) {
                return (current_ -> data_[index - 1] + 
                current_ -> data_[index]) / 2;
            }
            return current_ -> data_[index];
        }
        
        int sum() {
            int result = 0;
            for(int i = 0; i < current_ -> size_; i++) {
                result += current_ -> data_[i];
            }
            return result;
        }
        
        Iterator& ordered(bool ascending = true) {
            if(ascending) {
                sort(current_ -> data_, 
                current_ -> data_ + current_ -> size_);
            }
            else {
                sort(current_ -> data_, 
                current_ -> data_ + current_ -> size_);
                reverse(current_ -> data_, 
                current_ -> data_ + current_ -> size_);
            }
            return *this;
        }
    };

    ListOfArrays()
    : size_(0), head_(new ArrayNode(0, 0)) {
        head_ -> next_ = head_;
        head_ -> prev_ = head_;
    }

	~ListOfArrays() {
        while(!empty()) {
            pop();
        }
        delete head_;
    }

    ListOfArrays(const ListOfArrays& other) {
        head_ -> next_ = head_;
        head_ -> prev_ = head_;
        ArrayNode * node = other.head_ -> next_;
        while(node != other.head_) {
            push(node -> data_, 0, node -> size_);
            node = node -> next_;
        }
    }

	ListOfArrays& operator=(const ListOfArrays& other) {
        if(this != &other) {
            clear();
            ArrayNode * node = other.head_ -> next_;
            while(node != other.head_) {
                push(node -> data_, 0, node -> size_);
                node = node -> next_;
            }
        }
        return *this;
    }

    int size() {
        return size_;
    }

    void push(int array[], int position, int length) {
        ArrayNode * back = head_ -> prev_;
        int * arr = new int[length];
        int index = 0;
        for(int i = position; i < position + length; i++) {
            arr[i] = array[i];
        }
        ArrayNode * node = new ArrayNode(arr, length);
        back -> next_ = node;
        node -> prev_ = back;
        head_ -> prev_ = node;
        node -> next_ = head_;
        size_++;
    }

    void averages(double averages[]) {
        int index = 0;
        for(ListOfArrays::Iterator it = begin(); it != end(); it++) {
            averages[index] = it.average();
            index++;
        }
    }

    void medians(double medians[]) {
        int index = 0;
        for(ListOfArrays::Iterator it = begin(); it != end(); it++) {
            medians[index] = it.median();
            index++;
        }
    }
    
    void sizes(int sizes[]) {
        int index = 0;
        for(ListOfArrays::Iterator it = begin(); it != end(); it++) {
            sizes[index] = it.size();
            index++;
        }
    }
    
    void sums(int sums[]) {
        int index = 0;
        for(ListOfArrays::Iterator it = begin(); it != end(); it++) {
            sums[index] = it.sum();
            index++;
        }
    }

    Iterator begin() {
        return Iterator(*this, head_ -> next_);
    }

    Iterator end() {
        return Iterator(*this, head_);
    }

    ListOfArrays& ordered(bool ascending = true) {
        for(ListOfArrays::Iterator it = begin(); it != end(); it++) {
            it.ordered(ascending);
        }
        if(ascending) {

        }
        else {

        }
    }

    ListOfArrays& operator*=(const int& coef) {
        int index = 0;
        for(ListOfArrays::Iterator it = begin(); it != end(); it++) {
            for(int i = 0; i < it.size(); i++) {
                it[index] *= coef;
            }
        }
        return *this;
    }

    ListOfArrays& operator+=(const int& value) {
        for(ListOfArrays::Iterator it = begin(); it != end(); it++) {
            for(int i = 0; i < it.size(); i++) {
                it[i] += value;
            }
        }
        return *this;
    }

    void show() {
        int index = 0;
        for(ListOfArrays::Iterator it = begin(); it != end(); it++) {
            it.show();
            if(index != size_ - 1) {
                cout << "; ";
            }
            index++;
        }
    }
};

vector<string> split_commands(string& input);
void split_numbers(string numbers);

int main() {
    //string numbers = "1 2 3 4; 5 6; 7 8 9 10 11 12; 13 14 15";
    //getline(cin, numbers);
    //cout << numbers << endl;
    //split_numbers(numbers);
    /*string input = "mul:2.ordered:true.show.averages";
    vector<string> v = split_commands(input);*/
    /*for(vector<string>::iterator it = v.begin(); 
    it != v.end(); it++) {
        cout << *it << endl;
    }*/
    return 0;
}

vector<string> split_commands(string& input) {
    vector<string> v;
    int index = input.find(".");
    while(!input.empty()) {
        v.push_back(input.substr(0, index));
        input.erase(0, index + 1);
        index = input.find(".");
        if(index == string::npos) {
            v.push_back(input);
            input.clear();
        }
    }
    return v;
}

void split_numbers(string numbers) {
    regex re(";");
    vector<string> v {
        sregex_token_iterator(numbers.begin(), numbers.end(), re, -1), {}
    };
    for(vector<string>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
    cout << endl << endl << endl;
    regex del("\\s+");
    for(vector<string>::iterator it = v.begin(); it != v.end(); it++) {
        string str = *it;
        vector<string> v2 {
            sregex_token_iterator(str.begin(), str.end(), del, -1), {}
        };
        int arr[v2.size()];
        int index = 0;
        for(vector<string>::iterator iter = v2.begin(); iter != v2.end(); iter++) {
            string str2 = *iter;
            if(str2 != " " || str2 != "\n") {
                arr[index] = stoi(str2);
                index++;
            }
        }
    }
}