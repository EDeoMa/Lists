#pragma once
#include "TwoWayList.h"

class MyVector
{
public:
	MyVector();
	~MyVector();
	void additem(int pos, int data);
	int getitem(int pos);
	void eraseitem(int pos);
	int wrlen;
	int len;

private:
	int* mas;
};

MyVector::MyVector()
{
	mas = new int[10];
	len = 10;
	wrlen = 0;
}

MyVector::~MyVector()
{
	delete[] this->mas;
}

void MyVector::additem(int pos, int data)
{
	unsigned int strclock = clock();
	if (pos<wrlen+1 && pos<len) {
		this->mas[pos] = data;
		wrlen++;
	}
	if (pos - len == 1) {
		int* mas1 = new int[len * 2];
		len *= 2;
		for (int i = 0; i < len; i++) {
			mas1[i] = this->mas[i];
		}
		delete[] mas;
		mas = mas1;
		this->mas[pos] = data;
		wrlen++;
	}
	unsigned int stpclock = clock()-strclock;
	if (stpclock)
		cout << stpclock << endl;
}

int MyVector::getitem(int pos)
{
	return this->mas[pos];
}

void MyVector::eraseitem(int pos)
{
	for (int i = pos; i < this->wrlen-1; i++) {
		this->mas[pos] = this->mas[pos + 1];
	}
	wrlen--;
}
