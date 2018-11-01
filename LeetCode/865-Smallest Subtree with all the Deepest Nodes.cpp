#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	struct Result{
		TreeNode* node;
		int depth;
		Result(TreeNode* n, int d){
			node = n;
			depth = d;
		}
	};

public:
	Result divide(TreeNode* root){
		if (root == NULL)
			return Result(NULL, 0);
		Result left = divide(root->left);
		Result right = divide(root->right);
		if (left.depth < right.depth)
			return Result(right.node, right.depth + 1);
		else if (left.depth > right.depth)
			return Result(left.node, left.depth + 1);
		else
			return Result(root, left.depth + 1);
	}

	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		Result res = divide(root);
		return res.node;
	}
};