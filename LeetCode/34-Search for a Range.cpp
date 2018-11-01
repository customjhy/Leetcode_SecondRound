#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		auto right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
		vector<int> res;
		if (left >= right){
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		res.push_back(left);
		res.push_back(right - 1);
		return res;
	}
};