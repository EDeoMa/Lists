#pragma once
#include "ListNode.h"
#include "MyDataException.h"

template <class T> class TwoWayList{
public:
	TwoWayList();
	~TwoWayList();
	void insert(int pos, T data);
	T erase(int position);
	T operator[](int position);
	void push_back(T data);
	T pop_back();
	void push_front(T data);
	T pop_front();
	int size();

private:
	ListNode<T>* _head;
	ListNode<T>* _tail;
	int _size;
	bool verify_position(int position);
};

template <class T>
TwoWayList<T>::TwoWayList() {
	_head = new ListNode<T>();
	_tail = _head;
}

template <class T>
TwoWayList<T>::~TwoWayList() {
	ListNode<T>* curr = _head;
	while (curr->get_nxt()) {
		delete curr->get_prev();
		curr = curr->get_nxt();
	}
	delete curr;
}

template <class T>
void TwoWayList<T>::insert(int pos, T data) {
	if (!verify_position(pos)) {
		int i = pos + 1;
		ListNode<T>* curr = _head;
		while (curr->get_nxt() && i--) {
			curr = curr->get_nxt();
		}
		ListNode<T>* nlist = new ListNode<T>(data, nullptr, nullptr);
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

template <class T>
T TwoWayList<T>::operator[](int pos) {
	if (!verify_position(pos)) {
		int i = pos + 1;
		ListNode<T>* curr = _head;
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

template <class T>
T TwoWayList<T>::erase(int pos) {
	if (!verify_position(pos)) {
		T res = operator[](pos);
		int i;
		ListNode<T>* curr = _head;
		if (_size / 2 >= pos) {
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
		return res;
	}
	else throw myDataException();
}

template <class T>
void TwoWayList<T>::push_back(T data) {
	ListNode<T>* newNode = new ListNode<T>(data, nullptr, nullptr);
	_tail->set_nxt(newNode);
	newNode->set_prev(_tail);
	_tail = newNode;
	_size++;
}

template <class T>
T TwoWayList<T>::pop_back() {
	return erase(_size - 1);
}

template <class T>
void TwoWayList<T>::push_front(T data) {
	insert(0, data);
}

template <class T>
T TwoWayList<T>::pop_front() {
	return erase(0);
}

template <class T>
int TwoWayList<T>::size() {
	return _size;
}

template <class T>
bool TwoWayList<T>::verify_position(int pos) {
	if (pos >= 0 && pos < size() + 1)
		return false;
	else return true;
}