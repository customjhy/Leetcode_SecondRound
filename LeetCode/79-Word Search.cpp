#include<vector>

using namespace std;

class Solution {
public:
	//int m, n;
	//int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

	//bool valid(int i, int j){
	//	return i >= 0 && i < m && j >= 0 && j < n;
	//}

	//bool backtrace(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visit, string word, int start) {
	//	if (start == word.length())
	//		return true;
	//	for (int i = 0; i < 4; i++){
	//		int r = row + dir[i][0];
	//		int c = col + dir[i][1];
	//		if (valid(r, c) && !visit[r][c] && board[r][c] == word[start]){
	//			visit[r][c] = true;
	//			if (backtrace(board, r, c, visit, word, start + 1))
	//				return true;
	//			visit[r][c] = false;
	//		}
	//	}
	//	return false;
	//}

	//bool exist(vector<vector<char>>& board, string word) {
	//	if (word.empty())
	//		return true;
	//	if (board.empty() || board[0].empty())
	//		return false;
	//	m = board.size();
	//	n = board[0].size();
	//	vector<vector<bool>> visit(m, vector<bool>(n, false));
	//	for (int i = 0; i < m; i++){
	//		for (int j = 0; j < n; j++){
	//			if (board[i][j] != word[0])
	//				continue;
	//			visit[i][j] = true;
	//			if (backtrace(board, i, j, visit, word, 1))
	//				return true;
	//			visit[i][j] = false;
	//		}
	//	}
	//	return false;
	//}
};