#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

class Solution {
public:
	int m, n;

	int help(vector<vector<int>>& left, int row, int col){
		int width = left[row][col];
		int height = 1;
		int res = width * height;
		for (int i = row - 1; i >= 0; i--){
			if (left[i][col] == 0)
				break;
			width = min(width, left[i][col]);
			height++;
			res = max(res, width * height);
		}
		return res;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		m = matrix.size();
		n = matrix[0].size();
		vector<vector<int>> left(m, vector<int>(n, 0));
		int res = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (matrix[i][j] == '0')
					continue;
				left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
				res = max(res, help(left, i, j));
			}
		}
		return res;
	}
};