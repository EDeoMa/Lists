#pragma once
#include "MyList.h"


using namespace std;

class TwoWayList
{
public:
	TwoWayList();
	~TwoWayList();
	void additem(int, int);
	int getitem(int);
	void eraseitem(int);

private:
	MyList* head;
	int len;
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

void TwoWayList::additem(int pos, int data)
{
	int i = pos;
	MyList* curr = this->head;
	while (curr->nxt && i--)
	{
		curr = curr->nxt;
	}
	MyList* nlist = new MyList(data, curr->prev, curr->nxt);
	curr->prev->nxt = nlist;
	curr->prev = nlist;
}

int TwoWayList::getitem(int pos)
{
	int i = pos;
	MyList* curr = this->head;
	while (curr->nxt && i--)
	{
		curr = curr->nxt;
	}
	if (!i) {
		return curr->data;
	}
	else return -1;
}

void TwoWayList::eraseitem(int pos)
{
	int i = pos;
	MyList* curr = this->head;
	while (curr->nxt && i--)
	{
		curr = curr->nxt;
	}
	curr->prev->nxt = curr->nxt;
	curr->nxt->prev = curr->prev;
	delete curr;
}