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
	int numDecodings(string s) {
		if (s.empty()) return 0;
		int n = s.length();
		int mod = 1000000007;
		vector<long long> dp(n + 1, 1);
		if (s[0] == '0')
			return 0;
		if (s[0] == '*')
			dp[1] = 9;
		else
			dp[1] = 1;
		for (int i = 1; i < n; i++){
			if (s[i] == '*'){
				dp[i + 1] = (9 * dp[i]) % mod;
				if (s[i - 1] == '*'){
					dp[i + 1] += (15 * dp[i - 1]) % mod;
				}
				else if (s[i - 1] == '1'){
					dp[i + 1] += (9 * dp[i - 1]) % mod;
				}
				else if (s[i - 1] == '2'){
					dp[i + 1] += (6 * dp[i - 1]) % mod;
				}
			}
			else if (s[i] == '0'){
				if (s[i - 1] == '1' || s[i - 1] == '2'){
					dp[i + 1] = dp[i - 1];
				}
				else if (s[i - 1] == '*'){
					dp[i + 1] = (2 * dp[i - 1]) % mod;
				}else
					return 0;
			}
			else if (s[i] >= '1' && s[i] <= '6'){
				dp[i + 1] = dp[i];
				if (s[i - 1] == '1' || s[i - 1] == '2'){
					dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
				}
				else if (s[i - 1] == '*'){
					dp[i + 1] = (dp[i + 1] + 2 * dp[i - 1]) % mod;
				}
			}
			else{
				dp[i + 1] = dp[i];
				if (s[i - 1] == '1' || s[i - 1] == '*'){
					dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
				}
			}
		}
		return (int)dp[n];
	}
};