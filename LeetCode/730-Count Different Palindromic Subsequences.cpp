#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	vector<vector<int>> DP;
	int mod = 1000000007;

	int dp(string& S, int left, int right){
		if (left > right)
			return 0;
		if (DP[left][right] != -1)
			return DP[left][right];
		int res = 0;
		if (left == right)
			res = 1;
		else{
			if (S[left] != S[right]){
				res = dp(S, left + 1, right) + dp(S, left, right - 1) - dp(S, left + 1, right - 1);
			}
			else{
				int low = left + 1;
				int high = right - 1;
				while (low < right && S[low] != S[right])
					low++;
				while (high > left && S[high] != S[right])
					high--;
				if (low > high){
					res = 2 * dp(S, left + 1, right - 1) + 2;
				}
				else if (low == high){
					res = 2 * dp(S, left + 1, right - 1) + 1;
				}
				else{
					res = 2 * dp(S, left + 1, right - 1) - dp(S, low + 1, high - 1);
				}
			}
		}
		res = res >= 0 ? res % mod : res + mod;
		DP[left][right] = res;
		return res;
	}

	int countPalindromicSubsequences(string S) {
		int len = S.length();
		DP = vector<vector<int>>(len, vector<int>(len, -1));
		return dp(S, 0, len - 1);
	}
};