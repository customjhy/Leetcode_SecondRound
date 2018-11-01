#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	int N;

	void help(vector<vector<int>>& grid, vector<vector<bool>>& visit, int row, int col, int depth){
		if (row < 0 || row >= N || col < 0 || col >= N || grid[row][col] > depth)
			return;
		int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		visit[row][col] = true;
		for (int i = 0; i < 4; i++){
			int r = row + dir[i][0];
			int c = col + dir[i][1];
			if (!visit[r][c] && grid[r][c] <= depth){
				help(grid, visit, r, c, depth);
			}
		}
	}

	bool valid(vector<vector<int>>& grid, int depth){
		vector<vector<bool>> visit(N, vector<bool>(N, false));
		help(grid, visit, 0, 0, depth);
		return visit[N - 1][N - 1];
	}

	int swimInWater(vector<vector<int>>& grid) {
		N = grid.size();
		if (N == 0)
			return 0;
		if (N == 1)
			return 1;
		int left = 0;
		int right = N * N - 1;
		while (left < right){
			int mid = (left + right) >> 1;
			if (valid(grid, mid)){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
		return left;
	}
};