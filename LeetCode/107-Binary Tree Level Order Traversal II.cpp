#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> result;
	stack<vector<int>> sta;
	queue<TreeNode*> que;
	int num;
	TreeNode* temp;
	vector<int> subresult;
	if (root)que.push(root);
	while (!que.empty()){
		subresult.clear();
		num = que.size();
		for (int i = 0; i < num; i++){
			temp = que.front();
			que.pop();
			subresult.push_back(temp->val);
			if (temp->left)que.push(temp->left);
			if (temp->right)que.push(temp->right);
		}
		sta.push(subresult);
	}
	while (!sta.empty()){
		subresult = sta.top();
		sta.pop();
		result.push_back(subresult);
	}
	return result;
}