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
	int findRotateSteps(string ring, string key) {
		if (key.length() == 0)
			return 0;
		int n = key.length();
		int m = ring.length();
		vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
		for (int i = 0; i < m; i++){
			if (ring[i] == key[0]){
				dp[0][i] = min(i, m - i) + 1;
			}
		}
		for (int i = 1; i < n; i++){
			for (int j = 0; j < m; j++){
				if (key[i] == ring[j]){
					for (int k = 0; k < m; k++){
						if (dp[i - 1][k] == INT_MAX)
							continue;
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1 + min(i - k < 0 ? i - k + m : i - k, k - i < 0 ? k - i + m : k - i));
					}
				}
			}
		}
		int res = INT_MAX;
		for (int i = 0; i < m; i++){
			res = min(res, dp[n - 1][i]);
		}
		return res;
	}
};