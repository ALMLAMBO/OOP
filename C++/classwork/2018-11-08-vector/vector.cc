#include <iostream>
#include <string>

using namespace std;

class VectorException {
	string message_;
public:
	VectorException(string message) {
		message_ = message;
	}

	string get_message() {
		return message_;
	}
};

class Vector {
	int capacity_;
	int size_;
	int * data_;

	void resize() {
		if(capacity_== 0) {
			capacity_ = 1;
		}
		else {
			capacity_ *= 2;
		}
		int * new_data = new int[capacity_];
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
	Vector() : capacity_(0),
	size_(0), data_(new int[capacity_]) {}

	Vector(int capacity) : capacity_(capacity),
	size_(0), data_(new int[capacity_]) {}

	Vector(const Vector& other) {
		capacity_ = other.capacity_;
		data_ = new int[capacity_];
		size_ = other.size_;
		for(int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
	}

	~Vector() {
		size_ = 0;
		capacity_ = 0;
		delete []data_;
	}

	void push_back(int value) {
		if(size_ == capacity_) {
			resize();
		}
		data_[size_] = value;
		size_++;
	}

	bool empty() const {
		return size_ == 0;
	}

	void pop_back() {
		if(empty()) {
			throw VectorException("Try to pop on empty vector");
		}
		data_[size_] = 0;
		size_--;
	}

	int& front() {
		if(empty()) {
			throw VectorException("Call front on an empty vector");
		}
		return data_[0];
	}

	int& back() {
		if(empty()) {
			throw VectorException("Call back on an empty vector");
		}
		return data_[size_ - 1];
	}

	const int& front() const {
		if(empty()) {
			throw VectorException("Call front on an empty vector");
		}
		return data_[0];
	}

	const int& back() const {
		if(empty()) {
			throw VectorException("Call back on an empty vector");
		}
		return data_[size_ - 1];
	}

	int size() const {
		return size_;
	}

	int capacity() const {
		return capacity_;
	}

	Vector& operator=(const Vector& other) {
		capacity_ = other.capacity_;
		delete []data_;
		data_ = new int[capacity_];
		size_ = other.size_;
		for(int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
	}

	int& operator[](int index) {
		return data_[index];
	}

	const int& operator[](int index) const {
		return data_[index];
	}

	int& at(int index) {
		return data_[index];
	}

	const int& at(int index) const {
		return data_[index];
	}

	class iterator {
		int index_;
		Vector * vector_;
		iterator(int index) : index_(index) {}
		friend class Vector;
		public:
			iterator() : index_(0) {}
			iterator(int index, Vector * vector) :
			index_(index), vector_(vector) {}
			int& operator*() {
				return vector_ -> data_[index_];
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

			iterator& operator+(int value) {
                index_ += value;
                if(index_ > vector_ -> size_) {
                    throw VectorException("out_of_range");
                }
                return *this;
			}

			iterator& operator-(int value) {
                index_ -= value;
                if(index_ < 0) {
                    throw VectorException("out_of_range");
                }
                return *this;
			}

			bool operator==(const iterator& other) const {
				return index_ == other.index_;
			}

			bool operator!=(const iterator& other) const {
				return !operator==(other);
			}

			bool operator<=(const iterator& other) const {
                return index_ <= other.index_;
			}

			bool operator>=(const iterator& other) const {
                return !operator<=(other);
			}

			bool operator<(const iterator& other) const {
                return index_ < other.index_;
			}

			bool operator>(const iterator& other) const {
                return !operator<(other);
			}
	};

	class const_iterator {
		friend class Vector;
		int index_;
		Vector * vector_;
		const_iterator(int index) : index_(index) {}
	public:
		const_iterator() : index_(0) {}
		const_iterator(int index, Vector * vector) :
		index_(index), vector_(vector) {}
		const int& operator*() {
			return vector_ -> data_[index_];
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
		friend class Vector;
		int index_;
		Vector * vector_;
		reverse_iterator(int index) : index_(index) {}
	public:
		reverse_iterator() : index_(vector_ -> size_ - 1) {}
		reverse_iterator(int index, Vector * vector) :
		index_(index - 1), vector_(vector) {}
		int& operator*() {
			return vector_ -> data_[index_];
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
		friend class Vector;
		int index_;
		Vector * vector_;
		const_reverse_iterator(int index) : index_(index) {}
	public:
		const_reverse_iterator(int index, Vector * vector) :
		index_(index - 1), vector_(vector) {}
		const_reverse_iterator() : index_(0) {}
		const int& operator*() {
			return vector_ -> data_[index_];
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

	iterator insert(iterator iter, int value) {
        if(size_ == capacity_) {
            resize();
        }
        int index = 0;
        for(Vector::iterator it = end(); it != iter; it--) {
            data_[it.index_] = data_[it.index_ - 1];
            index = it.index_;
        }
        data_[index] = value;
        size_++;
		return iterator();
	}

	iterator erase(iterator iter) {
		if(empty()) {
			throw VectorException("Try to erase on empty vector");
		}
		int index;
		for(Vector::iterator it = iter; it != end(); it++) {
            data_[it.index_ - 1] = data_[it.index_];
            index = it.index_;
        }
        size_--;
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

int main() {
	try{
		Vector v1;
		for(int i = 0; i < 10; i++) {
			v1.push_back(i * 2);
		}
		cout << "Normal iterator" << endl;
		for(Vector::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << "element = " << *it << endl;
		}
		cout << "Const iterator" << endl;
		for(Vector::const_iterator it = v1.cbegin(); it != v1.cend(); it++) {
			cout << "element = " << *it << endl;
		}
		cout << "Reverse iterator" << endl;
		for(Vector::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {
			cout << "element = " << *it << endl;
		}
		cout << "Const reverse iterator" << endl;
		for(Vector::const_reverse_iterator it = v1.crbegin(); it != v1.crend(); it++) {
			cout << "element = " << *it << endl;
		}
		cout << "Size = " << v1.size() << endl;
		cout << "Insert method" << endl;
		Vector::iterator iter = v1.insert(v1.begin() + 2, 100);
		for(Vector::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << "element = " << *it << endl;
		}
		cout << "Size = " << v1.size() << endl;
		cout << "Erase method" << endl;
        Vector::iterator iter2 = v1.erase(v1.begin() + 4);
        for(Vector::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << "element = " << *it << endl;
		}
		cout << "Erase range" << endl;
		Vector::iterator iter3 = v1.erase(v1.begin() + 3, v1.end() - 2);
		for(Vector::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << "element = " << *it << endl;
		}
	}
	catch(VectorException e) {
		cout << e.get_message() << endl;
	}
	return 0;
}
