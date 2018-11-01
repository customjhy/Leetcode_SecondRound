#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int help(vector<vector<int>>& dp, int i, int j){
		if (i < 0 || j < 0 || i >= dp.size() || j >= dp.size() || i > j){
			return 0;
		}
		return dp[i][j];
	}

	bool stoneGame(vector<int>& piles) {
		int size = piles.size();
		vector<vector<int>> dp(size, vector<int>(size, 0));
		for (int i = size - 1; i >= 0; i--){
			for (int j = i; j < size; j++){
				dp[i][j] = max(piles[i] - help(dp, i + 1, j), piles[j] - help(dp, i, j - 1));
			}
		}
		return dp[0][size - 1] > 0;
	}
};