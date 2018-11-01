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
	vector<vector<int>> vec;

	int dp(int left, int right){
		if (vec[left][right] != -1)
			return vec[left][right];
		if (left >= right)
			return 0;
		int res = INT_MAX;
		for (int i = left; i <= right; i++){
			int l = dp(left, i - 1);
			int r = dp(i + 1, right);
			res = min(res, i + max(l, r));
		}
		vec[left][right] = res;
		return res;
	}

	int getMoneyAmount(int n) {
		vec = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
		return dp(1, n);
	}
};