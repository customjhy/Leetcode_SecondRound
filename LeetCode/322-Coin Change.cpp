#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
		if (amount < 0)
			return -1;
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++){
			for (int j = 0; j < coins.size(); j++){
				if (i >= coins[j])
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};


/*
//TTL
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
		if (amount < 0)
			return -1;
		unordered_map<int, int> m;
		sort(coins.begin(), coins.end());
		m[0] = 0;
		return dfsMemory(amount, coins, m);
	}

	int dfsMemory(int amount, vector<int>& coins, unordered_map<int, int> m){
		if (m.count(amount) == 1)
			return m[amount];
		int res = INT_MAX;
		for (int i = 0; i < coins.size(); i++){
			if (amount >= coins[i]){
				int temp = dfsMemory(amount - coins[i], coins, m) + 1;
				if (temp == 0)
					continue;
				res = min(res, temp);
			}
			else{
				break;
			}
		}
		m[amount] = res;
		return res == INT_MAX ? -1 : res;
	}
};
*/