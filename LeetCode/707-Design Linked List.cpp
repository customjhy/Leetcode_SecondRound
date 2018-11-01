#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v){
		val = v;
		next = NULL;
	}
};

class MyLinkedList {
public:
	ListNode* head;
	ListNode* tail;

	/** Initialize your data structure here. */
	MyLinkedList() {
		head = NULL;
		tail = NULL;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		ListNode* temp = head;
		while (temp != NULL && index > 0){
			temp = temp->next;
			index--;
		}
		return temp == NULL ? -1 : temp->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode* temp = new ListNode(val);
		if (head == NULL){
			head = temp;
			tail = temp;
			return;
		}
		temp->next = head;
		head = temp;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode* temp = new ListNode(val);
		if (tail == NULL){
			head = temp;
			tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index == 0){
			addAtHead(val);
			return;
		}
		ListNode* temp = head;
		ListNode* post = head;
		while (temp != NULL && index > 1){
			temp = temp->next;
			index--;
		}
		if (temp != NULL){
			post = temp->next;
			ListNode* node = new ListNode(val);
			temp->next = node;
			node->next = post;
			if (node->next == NULL){
				tail = node;
			}
		}
		else{
			return;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index == 0){
			if (head != NULL){
				head = head->next;
			}
			return;
		}
		ListNode* temp = head;
		while (temp != NULL && index > 1){
			temp = temp->next;
			index--;
		}
		if (temp == NULL || temp->next == NULL){
			return;
		}
		temp->next = temp->next->next;
		if (temp->next == NULL){
			tail = temp;
		}
	}
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList obj = new MyLinkedList();
* int param_1 = obj.get(index);
* obj.addAtHead(val);
* obj.addAtTail(val);
* obj.addAtIndex(index,val);
* obj.deleteAtIndex(index);
*/