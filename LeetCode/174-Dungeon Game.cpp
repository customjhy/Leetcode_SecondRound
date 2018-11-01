#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
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
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty() || dungeon[0].empty())
			return 1;
		int n = dungeon.size();
		int m = dungeon[0].size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
		dp[n - 1][m - 1] = dungeon[n - 1][m - 1] > 0 ? 0 : dungeon[n - 1][m - 1];
		for (int i = n - 1; i >= 0; i--){
			for (int j = m - 1; j >= 0; j--){
				if (i == n - 1 && j == m - 1)
					continue;
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + dungeon[i][j];
				if (dp[i][j] > 0)
					dp[i][j] = 0;
			}
		}
		/*for(int i = 0;i < n;i++){
		for(int j  =0;j < m;j++){
		cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
		}*/
		return dp[0][0] > 0 ? 1 : 1 - dp[0][0];
	}
};