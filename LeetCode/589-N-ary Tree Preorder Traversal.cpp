#include<vector>
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
	vector<int> preorder(Node* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		stack<Node*> s;
		s.push(root);
		Node* temp = NULL;
		while (!s.empty()){
			temp = s.top();
			s.pop();
			res.push_back(temp->val);
			for (int i = temp->children.size() - 1; i >= 0; i--){
				s.push(temp->children[i]);
			}
		}
		return res;
	}
};