#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		if (nums.empty() || nums.size() < 2)return res;
		unordered_map<int, int> map;
		map[nums[0]] = 0;
		for (int i = 1; i < nums.size(); i++){
			if (map.count(target - nums[i]) == 1){
				res.push_back(map[target - nums[i]]);
				res.push_back(i);
				return res;
			}
			map[nums[i]] = i;
		}
		return res;
	}
};