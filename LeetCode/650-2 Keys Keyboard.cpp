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
	int minSteps(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[1] = 0;
		for (int i = 1; 2 * i <= n; i++){
			int copy = dp[i] + 1;
			for (int j = 2 * i; j <= n; j += i){
				dp[j] = min(dp[j], ++copy);
			}
		}
		return dp[n];
	}
};