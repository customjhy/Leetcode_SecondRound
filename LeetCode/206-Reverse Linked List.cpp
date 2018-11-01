#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//ListNode* reverseList(ListNode* head) {
//	if (head == NULL)return head;
//	if (head->next == NULL)return head;
//	ListNode* flag = head;
//	ListNode* p = head->next;
//	ListNode* temp;
//	head->next = NULL;
//	while (p->next){
//		temp = p;
//		p = temp->next;
//		temp->next = flag;
//		flag = temp;
//	}
//	p->next = flag;
//	return p;
//}
//
//ListNode* reverseList(ListNode* head) {
//	ListNode* pre = NULL;
//	while (head) {
//		ListNode* next = head->next;
//		head->next = pre;
//		pre = head;
//		head = next;
//	}
//	return pre;
//}