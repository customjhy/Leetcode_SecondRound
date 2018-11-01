#include<vector>

using namespace std;

class Solution {
public:
	int m;
	int n;

	void flipRow(vector<vector<int>>& A, int row){
		for (int i = 0; i < n; i++){
			if (A[row][i] == 0){
				A[row][i] = 1;
			}
			else{
				A[row][i] = 0;
			}
		}
	}

	void flipCol(vector<vector<int>>& A, int col){
		for (int i = 0; i < m; i++){
			if (A[i][col] == 0){
				A[i][col] = 1;
			}
			else{
				A[i][col] = 0;
			}
		}
	}

	int getBin(const vector<vector<int>>& A, int row){
		int res = 0;
		for (int i = 0; i < n; i++){
			res = res * 2 + A[row][i];
		}
		return res;
	}

	int matrixScore(vector<vector<int>>& A) {
		if (A.size() == 0 || A[0].empty())
			return 0;
		m = A.size();
		n = A[0].size();
		for (int i = 0; i < m; i++){//行首为0则逆转
			if (A[i][0] == 0){
				flipRow(A, i);
			}
		}
		for (int i = 1; i < n; i++){
			int times = 0;//统计每列出现1次数
			for (int j = 0; j < m; j++){
				if (A[j][i] == 1)
					times++;
			}
			if (times < (m + 1) / 2){
				flipCol(A, i);
			}
		}
		int res = 0;
		for (int i = 0; i < m; i++){
			res += getBin(A, i);
		}
		return res;
	}
};