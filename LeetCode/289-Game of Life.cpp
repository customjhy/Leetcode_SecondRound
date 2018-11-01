#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int n, m;

	bool valid(int i, int j){
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	int neighbour(vector<vector<int>>& board, int row, int col){
		int dir[] = { -1, 0, 1 };
		int res = 0;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (valid(row + dir[i], col + dir[j])){
					res += board[row + dir[i]][col + dir[j]] & 1;
				}
			}
		}
		return res - board[row][col] & 1;
	}

	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
			return;;
		n = board.size();
		m = board[0].size();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int count = neighbour(board, i, j);
				if (board[i][j] & 1){
					if (count == 2 || count == 3){
						board[i][j] = 3;
					}
				}
				else{
					if (count == 3){
						board[i][j] = 2;
					}
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				board[i][j] >>= 1;
			}
		}
	}
};