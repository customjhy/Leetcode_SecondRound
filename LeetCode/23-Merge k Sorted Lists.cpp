#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	struct cmp{
		bool operator() (ListNode* root1, ListNode* root2){
			return root1->val > root2->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
		ListNode* res = new ListNode(0);
		ListNode* head = res;
		for (int i = 0; i < lists.size(); i++){
			if (lists[0] != NULL)
				pq.push(lists[0]);
		}
		ListNode* temp = NULL;
		while (!pq.empty()){
			temp = pq.top();
			pq.pop();
			head->next = temp;
			head = head->next;
			if (temp->next != NULL){
				pq.push(temp->next);
			}
		}
		return res->next;
	}
};