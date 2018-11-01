#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>

using namespace std;
//
//class Solution {
//public:
//	const int mod = 1000000007;
//
//	vector<vector<vector<int>>> DP;
//	vector<int> group;
//	vector<int> profit;
//
//	int dp(int i, int g, int p){
//		if (i == 0){
//			if (p <= 0)return 1;
//			return 0;
//		}
//		if (p < 0)
//			p = 0;
//		if (DP[i][g][p] != INT_MIN)
//			return DP[i][g][p];
//		int res = dp(i - 1, g, p);
//		if (g >= group[i - 1]){
//			res = (res + dp(i - 1, g - group[i - 1], p - profit[i - 1])) % mod;
//		}
//		DP[i][g][p] = res;
//		return res;
//	}
//
//	int profitableSchemes(int G, int P, vector<int>& _group, vector<int>& _profit) {
//		group = _group;
//		profit = _profit;
//		int len = group.size();
//		DP = vector<vector<vector<int>>>(len + 1, vector<vector<int>>(P + 1, vector<int>(G + 1, INT_MIN)));
//		return dp(len, G, P);
//	}
//};

class Solution {
public:
	int mod = 1000000007;
	vector<int> group;
	vector<int> profit;
	vector<vector<vector<int>>> dp;

	int DP(int K, int G, int P){
		if (G < 0)
			return 0;
		if (P < 0)
			P = 0;
		if (dp[K][G][P] != -1){
			return dp[K][G][P];
		}
		int res = DP(K - 1, G, P) + DP(K - 1, G - group[K - 1], P - profit[K - 1]);
		res %= mod;
		dp[K][G][P] = res;
		return res;
	}

	int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
		int k = group.size();
		this->group = group;
		this->profit = profit;
		dp = vector<vector<vector<int>>>(k + 1, vector<vector<int>>(G + 1, vector<int>(P + 1, -1)));
		for (int i = 0; i <= G; i++){
			dp[0][i][0] = 1;
			for (int j = 1; j <= P; j++){
				dp[0][i][j] = 0;
			}
		}
		return DP(k, G, P);
	}
};