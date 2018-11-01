#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	stack<TreeNode*> pstack;
	stack<TreeNode*> qstack;
	while ((p || !pstack.empty()) || (q || !qstack.empty())){
		while (p || q){
			if (!p)return false;
			if (!q)return false;
			if (p->val != q->val)return false;
			pstack.push(p);
			qstack.push(q);
			p = p->left;
			q = q->left;
		}
		if (pstack.empty())return false;
		if (qstack.empty())return false;
		p = pstack.top();
		pstack.pop();
		q = qstack.top();
		qstack.pop();
		p = p->right;
		q = q->right;
	}
	return true;
}