#pragma once
const int minimumSize = 10;

class MyVector
{
public:
	MyVector();
	~MyVector();
	void insert(int, int);
	int operator[] (int);
	void erase(int);
	void push_back(int);
	void pop_back();
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

void MyVector::insert(int pos, int data)
{
	if (!checkpos(pos)) {
		if (this->_capacity == this->_size) {
			int* temp_array = new int[_capacity * 2];
			for (int i = 0; i < pos; i++) {
				temp_array[i] = this->_array[i];
			}
			temp_array[pos] = data;
			for (int i = pos+1; i < _capacity; i++) {
				temp_array[i] = this->_array[i];
			}
			_capacity *= 2;
			delete[] _array;
			this->_array = temp_array;
			this->_array[pos] = data;
			this->_size++;
		}
		else {
			for (int i = _size; i > pos; i--) {
				this->_array[i] = this->_array[i-1];
			}
			this->_array[pos] = data;
			this->_size++;
		}
	}
}

int MyVector::operator[](int pos)
{
	return this->_array[pos];
}

void MyVector::erase(int pos)
{
	for (int i = pos; i < this->_size - 1; i++) {
		this->_array[i] = this->_array[i + 1];
	}
	_size--;
}

void MyVector::push_back(int value)
{
	this->insert(this->size(), value);
}

void MyVector::pop_back()
{
	this->erase(this->size()-1);
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
	if (pos>=0 && pos<=this->capacity()+1 && pos<=this->size()+1)
		return 0;
	else return 1;
}
