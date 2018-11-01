#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
#include<functional>

using namespace std;


class Solution {
public:
	int n;

	bool valid(int i, int j){
		return i >= 0 && j >= 0 && i < n && j < n;
	}

	int help(vector<vector<int>>& grid, int row, int col){
		int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		int H = grid[row][col];
		int res = 0;
		for (int i = 0; i < 4; i++){
			int r = row + dir[i][0];
			int c = col + dir[i][1];
			if (!valid(r, c)){
				res += H;
			}
			else{
				if (H > grid[r][c]){
					res += H - grid[r][c];
				}
			}
		}
		return res;
	}

	int surfaceArea(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		n = grid.size();
		int res = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (grid[i][j] != 0){
					res += 2;
					res += help(grid, i, j);
				}
			}
		}
		return res;
	}
};