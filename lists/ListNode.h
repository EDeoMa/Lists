#pragma once
template <class T> class ListNode {
public:
	ListNode();
	ListNode(T, ListNode<T>* previous, ListNode<T>* next);
	ListNode<T>* get_prev();
	ListNode<T>* get_nxt();
	void set_prev(ListNode<T>* previous);
	void set_nxt(ListNode<T>* next);
	T get_data();
	void set_data(T data);
private:
	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _nxt;
};

template <class T>
ListNode<T>::ListNode() {
	_nxt = _prev = nullptr;
}

template <class T>
ListNode<T>::ListNode(T data, ListNode<T>* previous, ListNode<T>* next) {
	_data = data;
	_prev = previous;
	_nxt = next;
}

template <class T>
ListNode<T>* ListNode<T>::get_prev() { return _prev; }
template <class T>
ListNode<T>* ListNode<T>::get_nxt() { return _nxt; }
template <class T>
void ListNode<T>::set_prev(ListNode<T>* previous) { _prev = previous; }
template <class T>
void ListNode<T>::set_nxt(ListNode<T>* next) { _nxt = next; }
template <class T>
T ListNode<T>::get_data() { return _data; }
template <class T>
void ListNode<T>::set_data(T data) { _data = data; }