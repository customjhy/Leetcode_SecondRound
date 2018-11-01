#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* help(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight){
		if (preLeft > preRight)
			return NULL;
		TreeNode* root = new TreeNode(preorder[preLeft]); 
		int index = inLeft;
		for (int i = inLeft; i <= inRight; i++){
			if (inorder[i] == preorder[preLeft]){
				index = i;
				break;
			}
		}
		int sizeL = index - inLeft;
		int sizeR = inRight - index;
		root->left = help(preorder, preLeft + 1, preLeft + sizeL, inorder, inLeft, index - 1);
		root->right = help(preorder, preRight - sizeR + 1, preRight, inorder, index + 1, inRight);
		return root;
	}
	
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return help(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};