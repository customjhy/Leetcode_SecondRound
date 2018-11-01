#include<iostream>
#include<cstdio>
#include<stdio.h>
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
	int res;

	int numberOfArithmeticSlices(vector<int>& A) {
		res = 0;
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				for (int k = i - 1; k >= 0; k--){
					if (A[i] - A[k] == A[j] - A[i]){
						dp[i][j] += dp[k][i] + 1;
					}
				}
				res += dp[i][j];
			}
		}
		return res;
	}
};