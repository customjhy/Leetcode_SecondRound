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
	bool canCross(vector<int>& stones) {
		if (stones.size() <= 1)
			return true;
		if (stones[1] != stones[0] + 1)
			return false;
		int n = stones.size();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		dp[0][0] = true;
		dp[1][1] = true;
		for (int i = 2; i < stones.size(); i++){
			for (int j = i - 1; j >= 0; j++){
				int step = stones[i] - stones[j];
				if ( (step >= 0 && step < n && dp[j][step]) || (step - 1 >= 0 && step - 1 < n && dp[j][step - 1] )||(step + 1 >= 0 && step + 1 < n && dp[j][step + 1])){
					dp[i][step] = true;
				}
			}
		}
		for (int i = 0; i < n; i++){
			if (dp[n - 1][i])
				return true;
		}
		return false;
	}
};