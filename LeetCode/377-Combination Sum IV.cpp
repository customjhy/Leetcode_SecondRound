#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>

using namespace std;

//class Solution {
//public:
//	int combinationSum4(vector<int>& nums, int target) {
//		if (target == 0)
//			return 1;
//		if (nums.size() == 0)
//			return 0;
//		int n = nums.size();
//		vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//		for (int i = 0; i < n; i++){
//			dp[i][0] = 1;
//		}
//		for (int i = 0; i <= target; i += nums[0]){
//			dp[0][i] = 1;
//		}
//		for (int i = 1; i < n; i++){
//			for (int j = 1; j <= target; j++){
//				for (int k = 0; k <= j; k += nums[i]){
//					dp[i][j] += dp[i - 1][j - k];
//				}
//			}
//		}
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j <= target; j++){
//				cout << dp[i][j] << "\t";
//			}
//			cout << endl;
//		}
//		return dp[n - 1][target];
//	}
//};


class Solution {
public:
	vector<int> dp;
	vector<int> num;

	int DP(int n){
		if (dp[n] != -1)
			return dp[n];
		int res = 0;
		for (int i = 0; i < num.size(); i++){
			if (n >= num[i]){
				res += DP(n - num[i]);
			}
			else{
				break;
			}
		}
		dp[n] = res;
		return res;
	}

	int combinationSum4(vector<int>& nums, int target) {
		dp = vector<int>(target + 1, -1);
		dp[0] = 1;
		this->num = nums;
		sort(num.begin(), num.end());
		return DP(target);
	}
};

//
//int main(){
//	vector<int> nums{ 1, 2, 3 };
//	int target = 4;
//	cout << (new Solution())->combinationSum4(nums, target);
//
//	system("Pause");
//	return 0;
//}