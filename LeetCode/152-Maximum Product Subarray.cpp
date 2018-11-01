#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int res = nums[0];
		for (int i = 1, up = res, low = res; i < nums.size(); i++){
			if (nums[i] < 0){
				swap(up, low);
			}
			up = max(nums[i], up * nums[i]);
			low = min(nums[i], low * nums[i]);
			res = max(res, up);
		}
		return res;
	}
};