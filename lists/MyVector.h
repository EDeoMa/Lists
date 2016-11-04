#pragma once

#include "MyDataException.h"

class MyVector{
public:
	MyVector();
	~MyVector();
	void insert(int pos, int data);
	int erase(int);
	int operator[] (int);
	void push_back(int);
	int pop_back();
	int capacity();
	int size();

private:
	bool verify_position(int);
	int _size;
	int _capacity;
	int* _array;
};