#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		set<vector<int>> res;
		for (int i = 0; i < nums.size() - 2; i++){
			int sum = -nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right){
				if (nums[left] + nums[right] == sum){
					vector<int> temp(3);
					temp[0] = nums[i]; temp[1] = nums[left]; temp[2] = nums[right];
					res.insert(temp);
					left++;
					right--;
				}
				else if (nums[left] + nums[right] > sum){
					right--;
				}
				else{
					left++;
				}
			}
		}
		vector<vector<int>> trueRes(res.begin(), res.end());
		return trueRes;
	}
};