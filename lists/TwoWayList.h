#pragma once
#include "MyList.h"

class TwoWayList
{
public:
	TwoWayList();
	~TwoWayList();
	void insert(int, int);
	void erase(int);
	void push_back(int);
	void pop_back();
	void push_front(int);
	void pop_front();
	int getitem(int);
	int size();

private:
	MyList* head;
	int _size;
};

TwoWayList::TwoWayList()
{
	this->head = new MyList();
}

TwoWayList::~TwoWayList()
{
	MyList* curr = this->head;
	while (curr->nxt)
	{
		delete curr->prev;
		curr = curr->nxt;
	}
	delete curr;
}

void TwoWayList::insert(int pos, int data)
{
	int i = pos+1;
	MyList* curr = this->head;
	while (curr->nxt && i--)
	{
		curr = curr->nxt;
	}
	MyList* nlist = new MyList(data, nullptr, nullptr);
	if (!curr->nxt) {
		curr->nxt = nlist;
		nlist->prev = curr;
	}
	else {
		if (curr == this->head) {
			if (curr->nxt) {
				nlist->nxt = curr->nxt;
				curr->nxt->prev = nlist;
			}
			curr->nxt = nlist;
			nlist->prev = curr;
		}
		else {
			nlist->prev = curr->prev;
			nlist->nxt = curr;
			curr->prev->nxt = nlist;
			curr->prev = nlist;
		}
	}
	this->_size++;
}

int TwoWayList::getitem(int pos)
{
	int i = pos+1;
	MyList* curr = this->head;
	while (curr->nxt && i--)
	{
		curr = curr->nxt;
	}
	if (i == -1 && curr->nxt) {
		return curr->data;
	}
	else if (!curr->nxt)
		return curr->data;
}

void TwoWayList::erase(int pos)
{
	int i = pos+1;
	MyList* curr = this->head;
	while (curr->nxt && i--)
	{
		curr = curr->nxt;
	}
	if (!curr->nxt) {
		curr->prev->nxt = nullptr;
	}
	else {
		if (curr == this->head) {
			curr = curr->nxt;
		}
		curr->prev->nxt = curr->nxt;
		curr->nxt->prev = curr->prev;
	}
	this->_size--;
	delete curr;
}

inline void TwoWayList::push_back(int value)
{
	this->insert(this->_size, value);
}

inline void TwoWayList::pop_back()
{
	this->erase(this->_size - 1);
}

inline void TwoWayList::push_front(int value)
{
	this->insert(0, value);
}

inline void TwoWayList::pop_front()
{
	this->erase(0);
}

int TwoWayList::size()
{
	return this->_size;
}
