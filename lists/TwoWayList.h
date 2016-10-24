#pragma once
#include "ListNode.h"

//struct myDataException:std::exception {
//	char const *what() const noexcept {
//		return "Wrong position";
//	}
//};

class TwoWayList{
public:
	TwoWayList();
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
	ListNode* head;
	ListNode* tail;
	int _size;
	bool verify_position(int);
};

TwoWayList::TwoWayList(){
	head = new ListNode();
	tail = head;
}

TwoWayList::~TwoWayList(){
	ListNode* curr = head;
	while (curr->nxt){
		delete curr->prev;
		curr = curr->nxt;
	}
	delete curr;
}

void TwoWayList::insert(int pos, int data){
	if (!verify_position(pos)){
		int i = pos + 1;
		ListNode* curr = head;
		while (curr->nxt && i--){
			curr = curr->nxt;
		}
		ListNode* nlist = new ListNode(data, nullptr, nullptr);
		if (!curr->nxt) {
			curr->nxt = nlist;
			nlist->prev = curr;
			tail = nlist;
		}
		else {
			if (curr == head) {
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
		_size++;
	}
	else throw myDataException();
}

int TwoWayList::operator[](int pos){
	if (!verify_position(pos)){
		int i = pos + 1;
		ListNode* curr = head;
		while (curr->nxt && i--){
			curr = curr->nxt;
		}
		if (i == -1 && curr->nxt) {
			return curr->data;
		}
		else if (!curr->nxt)
			return curr->data;
	}
	else throw myDataException();
}

void TwoWayList::erase(int pos){
	if (!verify_position(pos)) {
		int i = pos + 1;
		ListNode* curr = head;
		while (curr->nxt && i--){
			curr = curr->nxt;
		}
		if (!curr->nxt) {
			tail = curr->prev;
			curr->prev->nxt = nullptr;
		}
		else {
			if (curr == head) {
				curr = curr->nxt;
			}
			curr->prev->nxt = curr->nxt;
			curr->nxt->prev = curr->prev;
		}
		_size--;
		delete curr;
	}
	else throw myDataException();
}

inline void TwoWayList::push_back(int value){
	ListNode* nlist = new ListNode(value, nullptr, nullptr);
	tail->nxt = nlist;
	nlist->prev = tail;
	tail = nlist;
	_size++;
}

inline void TwoWayList::pop_back(){
	erase(_size - 1);
}

inline void TwoWayList::push_front(int value){
	insert(0, value);
}

inline void TwoWayList::pop_front(){
	erase(0);
}

int TwoWayList::size(){
	return _size;
}

bool TwoWayList::verify_position(int pos){
	if (pos >= 0 && pos <= size() + 1)
		return false;
	else return true;
}