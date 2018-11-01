#include<vector>
#include<set>
#include<algorithm>

using namespace std;

bool cmp(const int& a, const int& b){
	return a > b;
}

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int num : nums)
			sum += num;
		if (sum % 2)
			return false;
		sum /= 2;
		vector<bool> visit(sum + 1, false);
		visit[0] = true;
		sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < nums.size(); i++){
			for (int j = sum; j >= 0; j--){
				if (visit[j]){
					if (j + nums[i] == sum)
						return true;
					else if (j + nums[i] > sum)
						continue;
					else{
						visit[j + nums[i]] = true;
					}
				}
			}
		}
	    return false;
	}
};