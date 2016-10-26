#pragma once
#include "ListNode.h"
#include "MyDataException.h"

class TwoWayList{
public:
	TwoWayList() {
		_head = new ListNode();
		_tail = _head;
	}
	~TwoWayList();
	void insert(int, int);
	void erase(int);
	int operator[](int);
	void push_back(int);
	void pop_back();
	void push_front(int);
	void pop_front();
	int size();

private:
	ListNode* _head;
	ListNode* _tail;
	int _size;
	bool verify_position(int);
};

