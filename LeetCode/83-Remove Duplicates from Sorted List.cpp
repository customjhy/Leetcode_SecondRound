#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL)return head;
	ListNode* prev = head;
	ListNode* cur = head->next;
	int number = head->val;
	while (cur){
		if (number == cur->val){
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
		else{
			number = cur->val;
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}