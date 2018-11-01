#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<functional>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.empty() && p.empty())
			return true;
		int m = s.length();
		int n = p.length();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= m; i++)
			dp[i][0] = false;
		for (int i = 1; i <= n; i++){
			if (p[i - 1] == '*'){
				dp[0][i] = dp[0][i - 1];
			}
			else{
				dp[0][i] = false;
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; i++){
				if (s[i] == p[j] || p[j] == '?'){
					dp[i + 1][j + 1] = dp[i][j];
				}
				else if (p[j] == '*'){
					for (int k = i + 1; k >= 0; k--){
						if (dp[k][j]){
							dp[i + 1][j + 1] = true;
							break;
						}
					}
				}
			}
		}
		return dp[m][n];
	}
};