#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		for (int i = 0; i <= right; i++){
			while (nums[i] == 2 && i < right)
				swap(nums[i], nums[right--]);			
			while (nums[i] == 0 && i > left)
				swap(nums[i], nums[left++]);
		}
	}
};

//int main(){
//	Solution* solu = new Solution();
//	int num[] = { 1, 2,0};
//	vector<int> nums(num, num + 3);
//	solu->sortColors(nums);
//	for (int i = 0; i < nums.size(); i++){
//		cout << nums[i] << "\t";
//	}
//	system("pause");
//	return 0;
//}