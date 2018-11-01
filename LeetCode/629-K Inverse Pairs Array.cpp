#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
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

class Solution {
public:
	int kInversePairs(int n, int k) {
		if (n == 0)
			return 0;
		if (k == 0)
			return 1;
		int mod = 1000000007;
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		for (int i = 1; i <= n; i++){
			dp[i][0] = 1;
		}
		for (int i = 1; i <= n; i++){
			int sum = dp[i - 1][0];
			for (int j = 1; j <= k; j++){
				sum += dp[i - 1][j];
				if (j - i >= 0){
					sum -= dp[i - 1][j - i];
				}
				sum %= mod;
				sum = sum < 0 ? sum + mod : sum;
				dp[i][j] = sum;
				//for (int k = max(0, j - i + 1); k <= j; k++){
				//	dp[i][j] += dp[i - 1][k];
				//	dp[i][j] %= mod;
				//}
			}
		}
		return dp[n][k];
	}
};

//int main(){
//	//663677020
//	int n = 1000;
//	int k = 1000;
//	cout << (new Solution())->kInversePairs(n, k) << endl;
//
//	system("Pause");
//	return 0;
//}