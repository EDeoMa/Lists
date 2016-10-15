#pragma once
#include "MyList.h"
#include <ctime>
#include <iostream>

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

}

inline void TwoWayList::additem(int pos, int data)
{
}

inline int TwoWayList::getitem(int pos)
{
	return 0;
}

inline void TwoWayList::eraseitem(int pos)
{
}

//void TwoWayList::addlist(int i)
//{
//	MyList* curr = this->head;
//	while (curr->nxt)
//	{
//		curr = curr->nxt;
//	}
//	curr->nxt = new MyList(i, curr, nullptr);
//}
//
//inline void TwoWayList::printlists()
//{
//	MyList* curr = this->head->nxt;
//	while (curr)
//	{
//		cout << curr->data << endl;
//		curr = curr->nxt;
//	}
//}
