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
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
		int res = INT_MIN;
		for (int i = 0; i <= m; i++){
			for (int j = 0; j <= n; j++){
				for (int row = i; row <= m; row++){
					for (int col = j; col <= n; col++){
						int temp = dp[row][col] - dp[i][col] - dp[row][j] + dp[i][j];
						if (temp <= k)
							res = max(res, temp);
					}
				}
			}
		}
		return res;
	}
};