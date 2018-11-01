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

//Solution1 : TLE
//class Solution {
//public:
//	vector<vector<int>> dp;
//	string str;
//
//	bool valid(int left, int right){
//		while (left < right){
//			if (str[left++] != str[right--])
//				return false;
//		}
//		return true;
//	}
//
//	int DP(int left, int right){
//		if (left >= right)
//			return 0;
//		if (dp[left][right] != -1)
//			return dp[left][right];
//		if (valid(left, right)){
//			dp[left][right] = 0;
//			return 0;
//		}
//		int res = INT_MAX;
//		for (int i = left; i < right; i++){
//			res = min(res, 1 + DP(left, i) + DP(i + 1, right));
//		}
//		dp[left][right] = res;
//		return res;
//	}
//
//	int minCut(string s) {
//		if (s.length() <= 1)
//			return 0;
//		int n = s.length();
//		dp = vector<vector<int>>(n, vector<int>(n, -1));
//		this->str = s;
//		return DP(0, n - 1);
//	}
//};

class Solution {
public:
	int minCut(string s) {
		if (s.length() <= 1)
			return 0;
		int n = s.length();
		vector<vector<bool>> valid(n, vector<bool>(n, false));
		vector<int> dp(n + 1, INT_MAX);
		dp[n] = -1;
		for (int i = n - 1; i >= 0; i--){
			dp[i] = n - i - 1;
			for (int j = i; j < n; j++){
				if (s[i] == s[j] && (j - i < 2 || valid[i + 1][j - 1])){
					valid[i][j] = true;
					dp[i] = min(dp[i], 1 + dp[j + 1]);
				}
			}
		}
		return dp[0];
	}
};