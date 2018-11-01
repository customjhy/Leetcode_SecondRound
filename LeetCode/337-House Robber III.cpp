#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	unordered_map<TreeNode*, int> yes;
	unordered_map<TreeNode*, int> no;

	int robYes(TreeNode* root){
		if (root == NULL)
			return 0;
		if (yes.count(root) == 1)
			return yes[root];
		int left = robNo(root->left);
		int right = robNo(root->right);
		int sum = root->val + left + right;
		yes[root] = sum;
		return sum;
	}

	int robNo(TreeNode* root){
		if (root == NULL)
			return 0;
		if (no.count(root) == 1)
			return no[root];
		int left = max(robNo(root->left), robYes(root->left));
		int right = max(robNo(root->right), robYes(root->right));
		int sum = left + right;
		no[root] = sum;
		return sum;
	}

	int rob(TreeNode* root) {
		return max(robYes(root), robNo(root));
	}
};