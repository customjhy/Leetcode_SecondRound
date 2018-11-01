#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* temp;
		while (node->next){
			node->val = node->next->val;
			temp = node;
			node = node->next;
		}
		temp->next = NULL;
		delete node;
	}
};