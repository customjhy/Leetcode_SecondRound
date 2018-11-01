#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*> que;
		int level = 0;
		que.push(root);
		TreeNode* temp = NULL;
		while (!que.empty()){
			int size = que.size();
			for (int i = 0; i < size; i++){
				temp = que.front();
				que.pop();
				if (temp->left != NULL){
					que.push(temp->left);
				}
				if (temp->right != NULL){
					que.push(temp->right);
				}
			}
			level++;
		}
		return level;
	}
};