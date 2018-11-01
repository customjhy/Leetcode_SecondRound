#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.empty())
			return vector<int>();
		sort(nums.begin(), nums.end());
		int res = 1;
		int index = 0;
		int n = nums.size();
		vector<int> dp(n, 1);
		for (int i = 1; i < n; i++){
			for (int j = i - 1; j >= 0; j--){
				if (nums[i] % nums[j] == 0){
					dp[i] = max(dp[i], dp[j] + 1);
					if (dp[i] > res){
						res = dp[i];
						index = i;
					}
				}
			}
		}
		vector<int> vec{ nums[index] };
		int cur = index;
		res--;
		for (int i = index - 1; i >= 0; i--){
			if (dp[i] == res && nums[cur] % nums[i] == 0){
				vec.push_back(nums[i]);
				cur = i;
				res--;
			}
		}
		return vec;
	}
};