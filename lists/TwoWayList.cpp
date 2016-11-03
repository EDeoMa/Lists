
#include "TwoWayList.h"

TwoWayList::~TwoWayList() {
	ListNode* curr = _head;
	while (curr->get_nxt()) {
		delete curr->get_prev();
		curr = curr->get_nxt();
	}
	delete curr;
}

void TwoWayList::insert(int pos, int data) {
	if (!verify_position(pos)) {
		int i = pos + 1;
		ListNode* curr = _head;
		while (curr->get_nxt() && i--) {
			curr = curr->get_nxt();
		}
		ListNode* nlist = new ListNode(data, nullptr, nullptr);
		if (!curr->get_nxt()) {
			curr->set_nxt(nlist);
			nlist->set_prev(curr);
			_tail = nlist;
		}
		else {
			if (curr == _head) {
				if (curr->get_nxt()) {
					nlist->set_nxt(curr->get_nxt());
					curr->get_nxt()->set_prev(nlist);
				}
				curr->set_nxt(nlist);
				nlist->set_prev(curr);
			}
			else {
				nlist->set_prev(curr->get_prev());
				nlist->set_nxt(curr);
				curr->get_prev()->set_nxt(nlist);
				curr->set_prev(nlist);
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
		while (curr->get_nxt() && i--) {
			curr = curr->get_nxt();
		}
		if (i == -1 && curr->get_nxt()) {
			return curr->get_data();
		}
		else if (!curr->get_nxt())
			return curr->get_data();
	}
	else throw myDataException();
}

void TwoWayList::erase(int pos) {
	if (!verify_position(pos)) {
		int i;
		ListNode* curr = _head;
		if (_size/2>=pos) {
			i = pos + 1;
			while (curr->get_nxt() && i--) {
				curr = curr->get_nxt();
			}
		}
		else {
			i = _size - pos;
			while (curr->get_prev() && i--) {
				curr = curr->get_prev();
			}
		}
		if (!curr->get_nxt()) {
			_tail = curr->get_prev();
			curr->get_prev()->set_nxt(nullptr);
		}
		else {
			if (curr == _head) {
				curr = curr->get_nxt();
			}
			curr->get_prev()->set_nxt(curr->get_nxt());
			curr->get_nxt()->set_prev(curr->get_prev());
		}
		_size--;
		delete curr;
	}
	else throw myDataException();
}

void TwoWayList::push_back(int value) {
	ListNode* newNode = new ListNode(value, nullptr, nullptr);
	_tail->set_nxt(newNode);
	newNode->set_prev(_tail);
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