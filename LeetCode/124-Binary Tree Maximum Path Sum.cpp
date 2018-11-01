#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<functional>
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
	int res;

	int help(TreeNode* root){
		if (root == NULL)
			return 0;
		int left = help(root->left);
		if (left < 0)
			left = 0;
		int right = help(root->right);
		if (right < 0)
			right = 0;
		res = max(res, root->val + left + right);
		return root->val + max(left, right);
	}

	int maxPathSum(TreeNode* root) {
		res = INT_MIN;
		int temp = help(root);
		res = max(res, temp);
		return res;
	}
};