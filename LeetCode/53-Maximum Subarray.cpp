#include<iostream>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int result = nums[0];
	int sum, pre_sum;
	for (int i = 0; i < nums.size(); i++){
		sum = nums[i];
		pre_sum = 0;
		for (int j = i + 1; j < nums.size(); j++){
			pre_sum += nums[j];
			if (pre_sum>0){
				sum += pre_sum;
				pre_sum = 0;
			}
		}
		if (sum>result)result = sum;
	}
	return result;
}