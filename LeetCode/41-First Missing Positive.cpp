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
	int firstMissingPositive(vector<int>& nums) {
		int N = nums.size();
		bool flag = false;
		for (int i = 0; i < N; i++){
			if (nums[i] < 0)
				nums[i] = INT_MIN;
			if (nums[i] == 1)
				flag = true;
		}
		if (!flag)
			return 1;
		for (int i = 0; i < N; i++){
			int temp = nums[i];
			if (temp == INT_MIN || abs(temp) > N || temp == 0){
				continue;
			}
			temp = abs(temp);
			if (nums[temp - 1] == INT_MIN || nums[temp - 1] == 0)
				nums[temp - 1] = -1;
			else
				nums[temp - 1] = -abs(nums[temp - 1]);
		}
		for (int i = 1; i < N; i++){
			if (nums[i] >= 0 || nums[i] == INT_MIN)
				return i + 1;
		}
		return N + 1;
	}
};