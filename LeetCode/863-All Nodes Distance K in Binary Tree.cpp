#include<vector>
#include<queue>
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct fatherNode {
	int val;
	fatherNode *left;
	fatherNode *right;
	fatherNode *father;
	fatherNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
};

class Solution {
public:
	fatherNode* buildTree(TreeNode* root, fatherNode* father){
		if (root == NULL)
			return NULL;
		fatherNode* cur = new fatherNode(root->val);
		cur->father = father;
		cur->left = buildTree(root->left, cur);
		cur->right = buildTree(root->right, cur);
		return cur;
	}

	void downward(vector<int>& res, fatherNode* fatherRoot, int K){
		if (fatherRoot == NULL)
			return;
		if (K == 0){
			res.push_back(fatherRoot->val);
			return;
		}
		downward(res, fatherRoot->left, K - 1);
		downward(res, fatherRoot->right, K - 1);
	}

	void upward(vector<int>& res, fatherNode* fatherRoot, fatherNode* son, int K){
		if (fatherRoot == NULL)
			return;
		if (K == 0){
			res.push_back(fatherRoot->val);
			return;
		}
		upward(res, fatherRoot->father, fatherRoot, K - 1);
		if (fatherRoot->left == son){
			downward(res, fatherRoot->right, K - 1);
		}
		else{
			downward(res, fatherRoot->left, K - 1);
		}
	}

	fatherNode* search(fatherNode* fatherRoot, TreeNode* target){
		if (fatherRoot == NULL)
			return NULL;
		if (fatherRoot->val == target->val)
			return fatherRoot;
		fatherNode* left = search(fatherRoot->left, target);
		if (left != NULL)
			return left;
		return search(fatherRoot->right, target);
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		vector<int> res;
		if (root == NULL || target == NULL)
			return res;
		if (K == 0){
			res.push_back(target->val);
			return res;
		}
		fatherNode* fatherRoot = buildTree(root, NULL);
		fatherRoot = search(fatherRoot, target);
		downward(res, fatherRoot->left, K - 1);
		downward(res, fatherRoot->right, K - 1);
		upward(res, fatherRoot->father, fatherRoot, K - 1);
		return res;
	}
};
//
//int main(){
//	vector<int> tree(10000, -1);
//	queue<int> q;
//	q.push(1);
//	int num = 0;
//	cin >> num;
//	while (num != -10){
//		int index = q.front();
//		q.pop();
//		tree[index] = num;
//		if (num != -1){
//			q.push(index * 2);
//			q.push(index * 2 + 1);
//		}
//		cout << "index:" <<index << endl;
//		cin >> num;
//	}
//	cout << "建树" << endl;
//	vector<int> res;
//	int index = 0;
//	for (int i = 1; i < 10000; i++){
//		if (tree[i] == 37){
//			index = i;
//			break;
//		}
//	}
//	Solution* solu = new Solution();
//	if (index != 1){
//		solu->upward(res, tree, index / 2, index, 16);
//		cout << "向上" << endl;
//	}
//	solu->downward(res, tree, index * 2, 16);
//	cout << "左子树" << endl;
//	solu->downward(res, tree, index * 2 + 1, 16);
//	cout << "右子树" << endl;
//	for (int r : res)
//		cout << r << "\t";
//	cout << "输出" << endl;
//	system("pause");
//	return 0;
//}

//0  1  29  2  3  41  43  11  4  -1  5  -1  -1  -1  -1  27  15  18  7  19  6  -1  36  -1  33  -1  -1  8  10  -1  22  -1  17  -1  -1  -1  -1  16  9  20  12  23  28  -1  39  34  -1  14  -1  46  42  26  13  31  -1  30  48  -1  -1  -1  -1  -1  37  -1  47  -1  -1  45  -1  21  44  -1  -1  -1  35  -1  49  -1  -1  -1  -1  -1  -1  24  32  -1  -1  -1  -1  -1  -1  25  -1  -1  -1  -1  38  -1  40  -10

//[0 1,29,2,3,41,43,11,4,-1,5,-1,-1,-1,-1,27,15,18,7,19,6,-1,36,-1,33,-1,-1,8,10,-1,22,-1,17,-1,-1,-1,-1,16,9,20,12,23,28,-1,39,34,-1,14,-1,46,42,26,13,31,-1,30,48,-1,-1,-1,-1,-1,37,-1,47,-1,-1,45,-1,21,44,-1,-1,-1,35,-1,49,-1,-1,-1,-1,-1,-1,24,32,-1,-1,-1,-1,-1,-1,25,-1,-1,-1,-1,38,-1,40,-10]
//37
//17