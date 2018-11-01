#include<iostream>
#include<cstdio>
#include<stdio.h>
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
	int numPermsDISequence(string S) {
		int mod = 1000000007;
		int n = S.length() + 1;
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		dp[1][1] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = 1; j <= i; j++){
				if (S[i - 2] == 'D'){
					dp[i][j] = ((dp[i][j - 1] + dp[i - 1][i - 1]) % mod - dp[i - 1][j - 1]) % mod;
				}
				else{
					dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
				}
			}
		}
		return (dp[n][n] + mod) % mod;
	}
};