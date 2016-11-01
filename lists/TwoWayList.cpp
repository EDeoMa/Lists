
#include "TwoWayList.h"

TwoWayList::~TwoWayList() {
	ListNode* curr = _head;
	while (curr->nxt) {
		delete curr->prev;
		curr = curr->nxt;
	}
	delete curr;
}

void TwoWayList::insert(int pos, int data) {
	if (!verify_position(pos)) {
		int i = pos + 1;
		ListNode* curr = _head;
		while (curr->nxt && i--) {
			curr = curr->nxt;
		}
		ListNode* nlist = new ListNode(data, nullptr, nullptr);
		if (!curr->nxt) {
			curr->nxt = nlist;
			nlist->prev = curr;
			_tail = nlist;
		}
		else {
			if (curr == _head) {
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

int TwoWayList::operator[](int pos) {
	if (!verify_position(pos)) {
		int i = pos + 1;
		ListNode* curr = _head;
		while (curr->nxt && i--) {
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

void TwoWayList::erase(int pos) {
	if (!verify_position(pos)) {
		int i = pos + 1;
		ListNode* curr = _head;
		while (curr->nxt && i--) {
			curr = curr->nxt;
		}
		if (!curr->nxt) {
			_tail = curr->prev;
			curr->prev->nxt = nullptr;
		}
		else {
			if (curr == _head) {
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

void TwoWayList::push_back(int value) {
	ListNode* newNode = new ListNode(value, nullptr, nullptr);
	_tail->nxt = newNode;
	newNode->prev = _tail;
	_tail = newNode;
	_size++;
}

void TwoWayList::pop_back() {
	erase(_size - 1);
}

void TwoWayList::push_front(int value) {
	insert(0, value);
}

void TwoWayList::pop_front() {
	erase(0);
}

int TwoWayList::size() {
	return _size;
}

bool TwoWayList::verify_position(int pos) {
	if (pos >= 0 && pos < size() + 1)
		return false;
	else return true;
}