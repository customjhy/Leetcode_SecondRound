#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		vector<vector<int>> res;
		res.push_back(vector<int>{r0, c0});
		int count = R * C - 1;
		int preR = r0;
		int preC = c0;
		int row, col;
		int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		int d = 0;
		int times = 1;
		bool flag = 0;
		while (count > 0){
			for (int i = 0; i < times; i++){
				row = preR + dir[d][0];
				col = preC + dir[d][1];
				preR = row;
				preC = col;
				if (row >= 0 && row < R && col >= 0 && col < C){
					res.push_back(vector<int>{row, col});
					count--;
				}
			}
			if (flag == false){
				flag = true;
			}
			else{
				flag = false;
				times++;
			}
			d = (d + 1) % 4;
		}
		return res;
	}
};