#include<vector>

using namespace std;

class Solution {
public:
	void help(vector<vector<int>>& matrix, vector<int>& vec, int up, int down, int left, int right){
		if (left > right || up > down)
			return;
		if (left == right){
			for (int i = up; i <= down; i++){
				vec.push_back(matrix[i][left]);
			}
			return;
		}
		if (up == down){
			for (int i = left; i <= right; i++){
				vec.push_back(matrix[up][i]);
			}
			return;
		}
		for (int i = left; i <= right - 1; i++){
			vec.push_back(matrix[up][i]);
		}
		for (int i = up; i <= down - 1; i++){
			vec.push_back(matrix[i][right]);
		}
		for (int i = right; i >= left + 1; i--){
			vec.push_back(matrix[down][i]);
		}
		for (int i = down; i >= up + 1; i--){
			vec.push_back(matrix[i][left]);
		}
		up++;
		down--;
		left++;
		right--;
		help(matrix, vec, up, down, left, right);
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty() || matrix[0].empty())
			return res;
		int m = matrix.size();
		int n = matrix[0].size();
		help(matrix, res, 0, m - 1, 0, n - 1);
		return res;
	}
};