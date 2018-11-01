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
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		if (s1.length() == 0)return s2 == s3;
		if (s2.length() == 0)return s1 == s3;
		int len1 = s1.length();
		int len2 = s2.length();
		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= len2; i++){
			if (s2[i - 1] == s3[i - 1])
				dp[0][i] = dp[0][i - 1];
			else
				dp[0][i] = false;
		}
		for (int i = 1; i <= len1; i++){
			if (s1[i - 1] == s3[i - 1])
				dp[i][0] = dp[i - 1][0];
			else
				dp[i][0] = false;
		}
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (s2[j - 1] == s3[i + j - 1]){
					dp[i][j] = dp[i][j] || dp[i][j - 1];
				}
				if (s1[i - 1] == s3[i + j - 1]){
					dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
			}
		}
		return dp[len1][len2];
	}
};