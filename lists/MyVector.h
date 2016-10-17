#pragma once
const int minimumSize = 10;

class MyVector
{
public:
	MyVector();
	~MyVector();
	void additem(int pos, int data);
	int operator[] (int pos);
	void eraseitem(int pos);
	int capacity();
	int size();

private:
	int checkpos(int);
	int _size;
	int _capacity;
	int* _array;
};

MyVector::MyVector()
{
	_array = new int[minimumSize];
	_capacity = minimumSize;
	_size = 0;
}

MyVector::~MyVector()
{
	delete[] this->_array;
}

void MyVector::additem(int pos, int data)
{
	if (!checkpos(pos)) {
		if (pos < _size + 1 && pos < _capacity) {
			this->_array[pos] = data;
			_size++;
		}
		if (pos - _capacity == 1) {
			int* temp_array = new int[_capacity * 2];
			_capacity *= 2;
			for (int i = 0; i < _capacity; i++) {
				temp_array[i] = this->_array[i];
			}
			delete[] _array;
			_array = temp_array;
			this->_array[pos] = data;
			_size++;
		}
	}
}

int MyVector::operator[](int pos)
{
	return this->_array[pos];
}

void MyVector::eraseitem(int pos)
{
	for (int i = pos; i < this->_size-1; i++) {
		this->_array[pos] = this->_array[pos + 1];
	}
	_size--;
}

inline int MyVector::capacity()
{
	return this->_capacity;
}

inline int MyVector::size()
{
	return this->_size;
}

int MyVector::checkpos(int pos)
{
	if (pos>=0 && pos<=this->capacity() && pos<=this->size())
		return 0;
	else return 1;
}
