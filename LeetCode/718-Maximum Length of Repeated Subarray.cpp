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
	int findLength(vector<int>& A, vector<int>& B) {
		if (A.empty() || B.empty())
			return 0;
		int res = 0;
		int m = A.size();
		int n = B.size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		if (A[0] == B[0])
			dp[0][0] = 1;
		for (int i = 1; i < m; i++){
			if (A[i] == B[0])
				dp[i][0] = 1;
		}
		for (int i = 1; i < n; i++){
			if (A[0] == B[i])
				dp[0][i] = 1;
		}
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				if (A[i] == B[j]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				res = max(res, dp[i][j]);
			}
		}
		return res;
	}
};