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
	const int mod = 1000000007;

	int numTilings(int N) {
		if (N == 0)
			return 0;
		if (N == 1)
			return 1;
		if (N == 2)
			return 2;
		vector<int> dp(N + 1, 1);
		dp[2] = 2;
		for (int i = 3; i <= N; i++){
			dp[i] = (dp[i - 1] * 2) % mod + dp[i - 3];
			dp[i] %= mod;
		}
		return dp[N];
	}
};