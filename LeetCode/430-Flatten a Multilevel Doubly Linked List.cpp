#include<vector>
#include<algorithm>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val = NULL;
	Node* prev = NULL;
	Node* next = NULL;
	Node* child = NULL;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
	Node* flatten(Node* head) {
		if (head == NULL)
			return head;
		Node* res = new Node(head->val, NULL, NULL, NULL);
		Node* temp = res;
		if (head->child != NULL){
			temp->next = flatten(head->child);
			temp->next->prev = temp;
		}
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = flatten(head->next);
		if (temp->next != NULL)
			temp->next->prev = temp;
		return res;
	}
};