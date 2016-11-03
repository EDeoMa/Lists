#pragma once
class ListNode {
public:
	ListNode();
	ListNode(int, ListNode*, ListNode*);
	ListNode* get_prev();
	ListNode* get_nxt();
	void set_prev(ListNode*);
	void set_nxt(ListNode*);
	int get_data();
	void set_data(int);
private:
	int _data;
	ListNode* _prev;
	ListNode* _nxt;
};

