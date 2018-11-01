#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>

using namespace std;

class Solution {
public:
	vector<vector<vector<int>>> dp;
	vector<vector<int>> grid;

	int DP(int step, int x1, int x2){
		int y1 = step - x1 - 1;
		int y2 = step - x2 - 1;
		if (step == 0 && x1 == 0 && x2 == 0)
			return 0;
		if (y1 < 0 || y2 < 0 || x1 < 0 || x2 < 0 || step < 0){
			return -1;
		}
		if (dp[step][x1][x2] != INT_MIN)
			return dp[step][x1][x2];
		if (grid[x1][y1] == -1 || grid[x2][y2] == -1){
			dp[step][x1][x2] = -1;
			return -1;
		}
		int res = -1;
		if (DP(step - 1, x1, x2) != -1){
			res = max(res, DP(step - 1, x1, x2));
		}
		if (DP(step - 1, x1 - 1, x2) != -1){
			res = max(res, DP(step - 1, x1 - 1, x2));
		}
		if (DP(step - 1, x1, x2 - 1) != -1){
			res = max(res, DP(step - 1, x1, x2 - 1));
		}
		if (DP(step - 1, x1 - 1, x2 - 1) != -1){
			res = max(res, DP(step - 1, x1 - 1, x2 - 1));
		}
		if (res != -1){
			res += grid[x1][y1];
			if (x2 != x1)
				res += grid[x2][y2];
		}
		dp[step][x1][x2] = res;
		return res;
	}

	int cherryPickup(vector<vector<int>>& grid) {
		int n = grid.size();
		dp = vector<vector<vector<int>>>(2 * n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
		this->grid = grid;
		return max(DP(2 * n - 1, n - 1, n - 1), 0);
	}
};