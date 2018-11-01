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
	vector<vector<int>> dp;
	string str;

	int DP(int i, int j){
		if (i == j)
			return 1;
		if (i > j)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		int res = 0;
		if (str[i] == str[j]){
			res = 2 + DP(i + 1, j - 1);
		}
		else{
			res = max(DP(i + 1, j), DP(i, j - 1));
		}
		dp[i][j] = res;
		return res;
	}

	int longestPalindromeSubseq(string s) {
		if (s.length() == 0)
			return 0;
		if (s.length() == 1)
			return 1;
		int len = s.length();
		this->str = s;
		dp = vector<vector<int>>(len, vector<int>(len, -1));
		return DP(0, len - 1);
	}
};