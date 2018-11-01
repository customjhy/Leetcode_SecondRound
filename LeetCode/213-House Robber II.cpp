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
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0)return 0;
		if (n == 1)return nums[0];
		vector<int> dp(n, 0);
		dp[1] = nums[1];
		for (int i = 2; i < n; i++){
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		int res = dp[n - 1];
		dp.resize(n, 0);
		dp[0] = nums[0];
		dp[1] = dp[0];
		for (int i = 2; i < n - 1; i++){
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		res = max(res, dp[n - 2]);
		return res;
	}
};