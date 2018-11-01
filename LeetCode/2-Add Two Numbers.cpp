#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* temp = head;
		int flag = 0;
		while (l1 != NULL && l2 != NULL){
			int count = l1->val + l2->val + flag;
			if (count >= 10){
				temp->next = new ListNode(count - 10);
				flag = 1;
			}
			else{
				temp->next = new ListNode(count);
				flag = 0;
			}
			temp = temp->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL){
			int count = l1->val + flag;
			if (count >= 10){
				temp->next = new ListNode(count - 10);
				flag = 1;
			}
			else{
				temp->next = new ListNode(count);
				flag = 0;
			}
			temp = temp->next;
			l1 = l1->next;
		}
		while (l2 != NULL){
			int count = l2->val + flag;
			if (count >= 10){
				temp->next = new ListNode(count - 10);
				flag = 1;
			}
			else{
				temp->next = new ListNode(count);
				flag = 0;
			}
			temp = temp->next;
			l2 = l2->next;
		}
		if (flag){
			temp->next = new ListNode(1);
		}
		return head->next;
	}
};