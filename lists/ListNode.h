#pragma once
class ListNode {
public:
	ListNode();
	ListNode(int, ListNode*, ListNode*);
	int data;
	ListNode* prev;
	ListNode* nxt;
};

inline ListNode::ListNode() {
	nxt = prev = nullptr;
}

inline ListNode::ListNode(int _data, ListNode* previous, ListNode* next) {
	data = _data;
	prev = previous;
	nxt = next;
}

