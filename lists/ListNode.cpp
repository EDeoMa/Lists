#include "ListNode.h"

ListNode::ListNode() {
	_nxt = _prev = nullptr;
}

ListNode::ListNode(int data, ListNode* previous, ListNode* next) {
	_data = data;
	_prev = previous;
	_nxt = next;
}

ListNode* ListNode::get_prev() { return _prev;  }
ListNode* ListNode::get_nxt() { return _nxt; }
void ListNode::set_prev(ListNode* previous) { _prev = previous; }
void ListNode::set_nxt(ListNode* next) { _nxt = next; }
int ListNode::get_data() { return _data;  }
void ListNode::set_data(int data) { _data = data; }