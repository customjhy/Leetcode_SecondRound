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
	vector<int> dp;

	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		int sum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
		if (sum < desiredTotal)
			return false;
		if (sum == desiredTotal){
			return maxChoosableInteger % 2;
		}
		if (desiredTotal <= 0)
			return true;
		dp = vector<int>(1 << maxChoosableInteger, 0);
		return help(maxChoosableInteger, 0, desiredTotal);
	}

	bool help(int maxChoose, int state, int target){
		if (target <= 0)
			return false;
		if (dp[state] != 0)
			return dp[state] == 1;
		for (int i = 0; i < maxChoose; i++){
			int pick = 1 << i;
			if (state & pick == 0){
				if (!help(maxChoose, state | pick, target - i - 1)){
					dp[state | pick] = 1;
					return true;
				}
			}
		}
		dp[state] = -1;
		return false;
	}
};