#pragma once

#include "MyDataException.h"

class MyVector{
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