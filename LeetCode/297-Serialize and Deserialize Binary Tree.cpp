#include<string>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == NULL)
			return "#";
		string res = "";
		res = res + to_string(root->val);
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* temp;
		while (!q.empty()){
			temp = q.front();
			q.pop();
			res += ",";
			if (temp->left != NULL){
				res += to_string(temp->left->val);
				q.push(temp->left);
			}
			else{
				res += "#";
			}
			res += ",";
			if (temp->right != NULL){
				res += to_string(temp->right->val);
				q.push(temp->right);
			}
			else{
				res += "#";
			}
		}
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.compare("#") == 0)
			return NULL;
		int left = 0;
		int right = 0;
		while (data[right] != ','){
			right++;
		}
		int val = stoi(data.substr(0, right));
		TreeNode* head = new TreeNode(val);
		TreeNode* temp = head;
		queue<TreeNode*> q;
		q.push(temp);
		while (right < data.length()){
			left = right + 1;
			right++;
			while (right < data.length() && data[right] != ',')
				right++;
			string sub = data.substr(left, right - left);
			temp = q.front();
			q.pop();
			if (sub.compare("#") == 0){
				temp->left = NULL;
			}
			else{
				temp->left = new TreeNode(stoi(sub));
				q.push(temp->left);
			}
			left = right + 1;
			right++;
			while (right < data.length() && data[right] != ',')
				right++;
			sub = data.substr(left, right - left);
			if (sub.compare("#") == 0){
				temp->right = NULL;
			}
			else{
				temp->right = new TreeNode(stoi(sub));
				q.push(temp->right);
			}
		}
		return head;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));