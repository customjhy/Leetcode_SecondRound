#include<iostream>
#include<vector>
#include<set>
#include<stack>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<int> postorder(Node* root) {
		set<Node*> s;
		stack<Node*> sta;
		vector<int> res;
		if (root == NULL)
			return res;
		sta.push(root);
		s.insert(root);
		Node* temp = NULL;
		while (!sta.empty()){
			temp = sta.top();
			sta.pop();
			if (s.find(temp) != s.end()){
				res.push_back(temp->val);
			}
			else{
				s.erase(temp);
				sta.push(temp);
				for (int i = temp->children.size() - 1; i >= 0; i--){
					sta.push(temp->children[i]);
					s.insert(temp->children[i]);
				}
			}
		}
		return res;
	}
};