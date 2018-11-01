#include<vector>
#include<unordered_map>
#include<queue>
#include<iostream>

using namespace std;

class Solution {
public:
	double exp = 0.0001;

	bool judgePoint24(vector<int>& nums) {
		vector<double> num;
		for (int i = 0; i < nums.size(); i++){
			num.push_back(nums[i]);
		}
		return help(num);
	}

	bool help(vector<double> nums){
		if (nums.size() == 1){
			if (nums[0] <= 24 + exp && nums[0] >= 24 - exp){
				return true;
			}
			else{
				return false;
			}
		}
		for (int i = 1; i < nums.size(); i++){
			for (int j = 0; j < i; j++){
				double num1 = nums[j];
				double num2 = nums[i];
				vector<double> vec{ num1 + num2, num1 - num2, num2 - num1, num1*num2 };
				if (num2 >= exp)vec.push_back(num1 / num2);
				if (num1 >= exp)vec.push_back(num2 / num1);

				nums.erase(nums.begin() + i);
				nums.erase(nums.begin() + j);
				for (int k = 0; k < vec.size(); k++){
					nums.push_back(vec[k]);
					if (help(nums))
						return true;
					nums.pop_back();
				}
				nums.insert(nums.begin() + j, num1);
				nums.insert(nums.begin() + i, num2);
			}
		}
		return false;
	}
};