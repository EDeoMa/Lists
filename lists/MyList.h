#pragma once
class MyList
{
public:
	MyList();
	MyList(int, MyList*, MyList*);
	~MyList();
	int data;
	MyList* prev;
	MyList* nxt;
};

MyList::MyList(){
	this->nxt = this->prev = nullptr;
}

MyList::MyList(int data, MyList* previous, MyList* next)
{
	this->data = data;
	this->prev = previous;
	this->nxt = next;
}

MyList::~MyList()
{
}