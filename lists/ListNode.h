#pragma once
class ListNode{
public:
	ListNode();
	ListNode(int, ListNode*, ListNode*);
	~ListNode();
	int data;
	ListNode* prev;
	ListNode* nxt;
};

ListNode::ListNode(){
	nxt = prev = nullptr;
}

ListNode::ListNode(int _data, ListNode* previous, ListNode* next){
	data = _data;
	prev = previous;
	nxt = next;
}

ListNode::~ListNode(){}