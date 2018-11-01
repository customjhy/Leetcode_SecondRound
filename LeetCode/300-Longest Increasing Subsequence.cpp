#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums) {
//		vector<int> dp;
//		int len = 0;
//		for (int num : nums){
//			int i = binary_search(dp.begin(), dp.end(), num);
//			if (i < 0)i = -(i + 1);
//			dp[i] = num;
//			if (i == len)len++;
//		}
//		return len;
//	}
//};

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;
		for (int num : nums){
			auto it = lower_bound(dp.begin(), dp.end(), num);
			if (it == dp.end())
				dp.push_back(num);
			else
				*it = num;
		}
		return dp.size();
	}
};