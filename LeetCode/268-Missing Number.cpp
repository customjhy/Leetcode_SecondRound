#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int>& nums) {
	int size = nums.size();
	if (size == 1 && nums[0] == 0)return 1;
	int flag = -1;
	for (int i = 0; i < size; i++){//find position of 0
		if (nums[i] == 0){
			flag = i;
			break;
		}
	}
	if (flag == -1)return 0;
	for (int i = 0; i < size; i++){
		nums[nums[i] % size] += size;
	}
	for (int i = 0; i < size; i++){
		if (nums[i] < size)return i;
		if (nums[i] == size&&i != flag)return i;
	}
	return size;
}