#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

class Solution {
public:
	int m, n;

	bool valid(int i, int j){
		return i >= 0 && i < m && j >= 0 && j < n;
	}

	int dfs(vector<vector<int>>& grid, int row, int col, int idx){
		if (grid[row][col] != 1)
			return 0;
		grid[row][col] = idx;
		int res = 1;
		int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		for (int i = 0; i < 4; i++){
			int r = row + dir[i][0];
			int c = col + dir[i][1];
			if (valid(r, c) && grid[r][c] == 1){
				res += dfs(grid, r, c, idx);
			}
		}
		return res;
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		int res = 0;
		int idx = 2;
		m = grid.size();
		n = grid[0].size();
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (grid[i][j] == 1){
					res = max(res, dfs(grid, i, j, idx++));
				}
			}
		}
		return res;
	}
};