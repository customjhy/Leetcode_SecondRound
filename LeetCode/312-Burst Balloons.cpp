#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	int maxCoins(vector<int>& nums) {
//		vector<int> iNums(nums.size() + 2);
//		int n = 1;
//		for (int num : nums){
//			if (num != 0){
//				iNums[n++] = num;
//			}
//		}
//		iNums[0] = 1;
//		iNums[n++] = 1;
//		vector<vector<int>> dp(n, vector<int>(n, 0));
//		for (int k = 2; k < n; k++){
//			for (int left = 0; left < n - k; left++){
//				int right = left + k;
//				for (int i = left + 1; i < right; i++){
//					dp[left][right] = max(dp[left][right], iNums[left] * iNums[i] * iNums[right] + dp[left][i] + dp[i][right]);
//				}
//			}
//		}
//		return dp[0][n - 1];
//	}
//};


class Solution {
public:
	int n;
	vector<int> num;
	vector<vector<int>> dp;

	int DP(int l, int r){
		if (l > r)
			return 0;
		if (dp[l][r] != -1)
			return dp[l][r];
		int res = 0;
		for (int i = l; i <= r; i++){
			res = max(res, DP(l, i - 1) + DP(i + 1, r) + num[i] * num[l - 1] * num[r + 1]);
		}
		dp[l][r] = res;
		return res;
	}

	int maxCoins(vector<int>& nums) {
		num = vector<int>(nums.size() + 2);
		n = 1;
		for (int t : nums){
			if (t != 0){
				num[n++] = t;
			}
		}
		num[0] = 1;
		num[n++] = 1;
		//num.assign(n);
		dp = vector<vector<int>>(n, vector<int>(n, -1));
		return DP(1, n - 2);

	}
};