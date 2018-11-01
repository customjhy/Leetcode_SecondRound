#include<vector>
#include<set>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		set<int> s(G.begin(), G.end());
		int res = 0;
		while (head != NULL){
			if (s.find(head->val) != s.end()){
				res++;
				while (head != NULL && s.find(head->val) != s.end()){
					head = head->next;
				}
				if (head == NULL)
					return res;
			}
			head = head->next;
		}
		return res;
	}
};