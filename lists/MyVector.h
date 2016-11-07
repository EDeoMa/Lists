#pragma once

#include "MyDataException.h"

template <class T> class MyVector{
public:
	MyVector();
	~MyVector();
	void insert(int pos, T data);
	T erase(int);
	T operator[] (int);
	void push_back(T);
	T pop_back();
	int capacity();
	int size();

private:
	bool verify_position(int);
	int _size;
	int _capacity;
	int* _array;
};

const int minimumSize = 10;

template <class T> 
MyVector<T>::MyVector() {
	_array = new T[minimumSize];
	_capacity = minimumSize;
	_size = 0;
}

template <class T>
MyVector<T>::~MyVector() {
	delete[] _array;
}

template <class T>
void MyVector<T>::insert(int pos, T data) {
	if (!verify_position(pos)) {
		if (_capacity == _size) {
			T* temp_array = new T[_capacity * 2];
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

template <class T>
T MyVector<T>::operator[](int pos) {
	if (!verify_position(pos))
		return _array[pos];
	else throw myDataException();
}

template <class T>
T MyVector<T>::erase(int pos) {
	if (!verify_position(pos)) {
		T res = operator[](pos);
		for (int i = pos; i < _size - 1; i++) {
			_array[i] = _array[i + 1];
		}
		_size--;
		return res;
	}
	else throw myDataException();
}

template <class T>
void MyVector<T>::push_back(T value) {
	insert(size(), value);
}

template <class T>
T MyVector<T>::pop_back() {
	return erase(size() - 1);
}

template <class T>
int MyVector<T>::capacity() {
	return _capacity;
}

template <class T>
int MyVector<T>::size() {
	return _size;
}

template <class T>
bool MyVector<T>::verify_position(int pos) {
	if (pos >= 0 && pos <= capacity() && pos <= size())
		return false;
	else return true;
}