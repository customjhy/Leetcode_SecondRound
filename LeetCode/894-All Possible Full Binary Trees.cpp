#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
#include<functional>

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

	/*bool equal(TreeNode* root1, TreeNode* root2){
		 if (root1 == NULL && root2 == NULL)
			 return true;
		 if (root1 == NULL || root2 == NULL)
			 return false;
		 return equal(root1->left, root2->left) && equal(root1->right, root2->right);
	 }*/

	 vector<TreeNode*> help(int n){
		 vector<TreeNode*> res;
		 if (n % 2 == 0)
			 return res;
		 TreeNode* root = new TreeNode(0);
		 if (n == 1){
			 res.push_back(root);
			 return res;
		 }
		 bool flag = false;
		 for (int i = 1; i < n; i += 2){
			 int j = n - 1 - i;
			 vector<TreeNode*> L = help(i);
			 vector<TreeNode*> R = help(j);
			 for (TreeNode* l : L){
				 for (TreeNode* r : R){
					 root->left = l;
					 root->right = r;
					 res.push_back(copy(root));
				 }
			 }
		 }
		 return res;
	 }

	 vector<TreeNode*> allPossibleFBT(int N) {
		 return help(N);
	 }
 };