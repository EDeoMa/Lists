#pragma once
const int minimumSize = 10;

class MyVector
{
public:
	MyVector();
	~MyVector();
	void insert(int, int);
	void erase(int);
	int operator[] (int);
	void push_back(int);
	void pop_back();
	int capacity();
	int size();

private:
	bool verify_position(int);
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
	delete[] _array;
}

void MyVector::insert(int pos, int data)
{
	if (!verify_position(pos)) {
		if (_capacity == _size) {
			int* temp_array = new int[_capacity * 2];
			for (int i = 0; i < pos; i++) {
				temp_array[i] = _array[i];
			}
			temp_array[pos] = data;
			for (int i = pos+1; i < _capacity; i++) {
				temp_array[i] = _array[i];
			}
			_capacity *= 2;
			delete[] _array;
			_array = temp_array;
			_array[pos] = data;
			_size++;
		}
		else {
			for (int i = _size; i > pos; i--) {
				_array[i] = _array[i-1];
			}
			_array[pos] = data;
			_size++;
		}
	}
}

int MyVector::operator[](int pos)
{
	return _array[pos];
}

void MyVector::erase(int pos)
{
	for (int i = pos; i < _size - 1; i++) {
		_array[i] = _array[i + 1];
	}
	_size--;
}

void MyVector::push_back(int value)
{
	insert(size(), value);
}

void MyVector::pop_back()
{
	erase(size()-1);
}

inline int MyVector::capacity()
{
	return _capacity;
}

inline int MyVector::size()
{
	return _size;
}

bool MyVector::verify_position(int pos)
{
	if (pos>=0 && pos<=capacity()+1 && pos<=size()+1)
		return 0;
	else return 1;
}
