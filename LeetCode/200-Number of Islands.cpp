#include<vector>

using namespace std;

class Solution {
public:
	//int m, n;
	//int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

	//bool valid(int i, int j){
	//	return i >= 0 && i < m && j >= 0 && j < n;
	//}

	//void alter(vector<vector<char>>& grid, int i, int j){
	//	grid[i][j] = '2';
	//	for (int k = 0; k < 4; k++){
	//		int row = i + dir[k][0];
	//		int col = j + dir[k][1];
	//		if (valid(row, col) && grid[row][col] == '1'){
	//			alter(grid, row, col);
	//		}
	//	}
	//}

	//int numIslands(vector<vector<char>>& grid) {
	//	if (grid.empty() || grid[0].empty())
	//		return 0;
	//	int res = 0;
	//	m = grid.size();
	//	n = grid[0].size();
	//	for (int i = 0; i < m; i++){
	//		for (int j = 0; j < n; j++){
	//			if (grid[i][j] == '1'){
	//				res++;
	//				alter(grid, i, j);
	//			}
	//		}
	//	}
	//	return res;
	//}
};