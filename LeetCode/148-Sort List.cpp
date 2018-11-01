#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* fast = head->next->next;
		ListNode* slow = head;
		while (fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* right = slow->next;
		slow->next = NULL;
		ListNode* left = head;
		left = sortList(left);
		right = sortList(right);
		if (left->val < right->val){
			head = left;
			left = left->next;
		}
		else{
			head = right;
			right = right->next;
		}
		ListNode* temp = head;
		while (left != NULL && right != NULL){
			if (left->val < right->val){
				head->next = left;
				left = left->next;
			}
			else{
				head->next = right;
				right = right->next;
			}
			head = head->next;
		}
		if (left == NULL)
			head->next = right;
		else{
			head->next = left;
		}
		return temp;
	}
};