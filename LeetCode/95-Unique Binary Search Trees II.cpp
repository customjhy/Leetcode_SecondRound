#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* copy(TreeNode* root){
		if (root == NULL)
			return NULL;
		TreeNode* res = new TreeNode(root->val);
		res->left = copy(root->left);
		res->right = copy(root->right);
		return res;
	}

	void add(TreeNode* root, int val){
		if (root == NULL)
			return;
		root->val += val;
		add(root->left, val);
		add(root->right, val);
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return vector<TreeNode*>();
		vector<vector<TreeNode*>> dp(n + 1);
		dp[0].push_back(NULL);
		for (int i = 1; i <= n; i++){
			for (int j = 0; j <= i - 1; j++){
				vector<TreeNode*> left = dp[j];
				vector<TreeNode*> right = dp[i - 1 - j];
				TreeNode* root = new TreeNode(j + 1);
				for (TreeNode* l : left){
					for (TreeNode* r : right){
						root->left = l;
						root->right = r;
						TreeNode* res = copy(root);
						add(res->right, j + 1);
						dp[i].push_back(res);
					}
				}
			}
		}
		return dp[n];
	}
};