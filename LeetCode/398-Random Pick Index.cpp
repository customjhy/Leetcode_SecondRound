#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

class Solution {
public:
	vector<int> sum;
	int total;

	Solution(vector<int> nums) {
		sum.resize(nums.size() + 1);
		sum[0] = 0;
		for (int i = 1; i < sum.size(); i++){
			sum[i] = sum[i - 1] + nums[i - 1];
		}
		total = sum[sum.size() - 1];
	}

	int pickIndex() {
		int pick = rand() % total;
		int left = 0;
		int right = sum.size() - 1;
		while (left <= right){
			int mid = (left + right) >> 1;
			if (sum[mid] <= pick){
				left = mid + 1;
			}
			else if(pick < sum[mid - 1]){
				right = mid - 1;
			}
			else{
				return mid - 1;
			}
		}
		return left - 1;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* int param_1 = obj.pick(target);
*/