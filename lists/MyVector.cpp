#include "MyVector.h"

const int minimumSize = 10;

MyVector::MyVector() {
	_array = new int[minimumSize];
	_capacity = minimumSize;
	_size = 0;
}

MyVector::~MyVector() {
	delete[] _array;
}

void MyVector::insert(int pos, int data) {
	if (!verify_position(pos)) {
		if (_capacity == _size) {
			int* temp_array = new int[_capacity * 2];
			for (int i = 0; i < pos; i++) {
				temp_array[i] = _array[i];
			}
			temp_array[pos] = data;
			for (int i = pos + 1; i < _capacity; i++) {
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
				_array[i] = _array[i - 1];
			}
			_array[pos] = data;
			_size++;
		}
	}
	else throw myDataException();
}

int MyVector::operator[](int pos) {
	if (!verify_position(pos))
		return _array[pos];
	else throw myDataException();
}

int MyVector::erase(int pos) {
	if (!verify_position(pos)) {
		int res = operator[](pos);
		for (int i = pos; i < _size - 1; i++) {
			_array[i] = _array[i + 1];
		}
		_size--;
		return res;
	}
	else throw myDataException();

}

void MyVector::push_back(int value) {
	insert(size(), value);
}

int MyVector::pop_back() {
	return erase(size() - 1);
}

inline int MyVector::capacity() {
	return _capacity;
}

inline int MyVector::size() {
	return _size;
}

bool MyVector::verify_position(int pos) {
	if (pos >= 0 && pos <= capacity()  && pos <= size())
		return false;
	else return true;
}
