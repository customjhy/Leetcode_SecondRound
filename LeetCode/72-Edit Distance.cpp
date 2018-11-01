#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length();
		int n = word2.length();
		if (m == 0)
			return n;
		if (n == 0)
			return m;
		vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
		if (word1[0] == word2[0])
			dp[0][0] = 0;
		else
			dp[0][0] = 1;
		for (int i = 1; i < n; i++){
			if (word1[0] == word2[i]){
				dp[0][i] = i;
			}
			else{
				dp[0][i] = 1 + dp[0][i - 1];
			}
		}
		for (int i = 1; i < m; i++){
			if (word1[i] == word2[0]){
				dp[i][0] = i;
			}
			else{
				dp[i][0] = 1 + dp[i - 1][0];
			}
		}
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				if (word1[i] == word2[j]){
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
				}
				else{
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};