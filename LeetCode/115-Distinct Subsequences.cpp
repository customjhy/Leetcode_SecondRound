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
	int numDistinct(string s, string t) {
		if (s.length() < t.length())
			return 0;
		if (t.length() == 0)
			return 1;
		int n = t.length();
		int m = s.length();
		vector<vector<int>> dp(n, vector<int>(m, 0));
		if (s[0] == t[0])
			dp[0][0] = 1;
		for (int i = 1; i < m; i++){
			dp[0][i] = dp[0][i - 1];
			if (t[0] == s[i]){
				dp[0][i]++;
			}
		}
		for (int i = 1; i < n; i++){
			for (int j = i; j < m; j++){
				dp[i][j] = dp[i][j - 1];
				if (t[i] == s[j]){
					dp[i][j] += dp[i - 1][j - 1];
				}
			}
		}
		return dp[n - 1][m - 1];
	}
};