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

using namespace std;

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		int n = pairs.size();
		if (n == 0)
			return 0;
		vector<int> dp(n, 1);
		int res = 1;
		for (int i = 1; i < n; i++){
			for (int j = i - 1; j >= 0; j--){
				if (pairs[i][0] > pairs[j][1]){
					dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};