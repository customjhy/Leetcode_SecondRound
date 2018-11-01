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
	vector<int> num;

	int dp(int left, int right){
		if (vec[left][right] != -1)
			return vec[left][right];
		int res = 0;
		if (left == right){
			res = num[left];
		}
		else{
			res = max(num[left] - dp(left + 1, right), num[right] - dp(left, right - 1));
		}
		vec[left][right] = res;
		return res;
	}


	bool PredictTheWinner(vector<int>& nums) {
		if (nums.empty())
			return true;
		int n = nums.size();
		num = nums;
		vec = vector<vector<int>>(n, vector<int>(n, -1));
		return dp(0, n - 1) >= 0;
	}
};