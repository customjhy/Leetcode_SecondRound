#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<functional>

using namespace std;

class Solution {
public:
	int m, n;

	bool valid(int i, int j){
		return i >= 0 && i < m && j >= 0 && j < n;
	}

	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col){
		if (dp[row][col] != -1)
			return dp[row][col];
		int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		int res = 1;
		for (int i = 0; i < 4; i++){
			int r = row + dir[i][0];
			int c = col + dir[i][1];
			if (valid(r, c) && matrix[r][c] > matrix[row][col]){
				res = max(res, 1 + dfs(matrix, dp, r, c));
			}
		}
		dp[row][col] = res;
		return res;
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		m = matrix.size();
		n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		int res = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				res = max(res, dfs(matrix, dp, i, j));
			}
		}
		return res;
	}
};