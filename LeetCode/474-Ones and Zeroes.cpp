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
	int findMaxForm(vector<string>& strs, int m, int n) {
		if (strs.size() == 0)
			return 0;
		vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
		//int dp[601][101][101];
		//memset(dp, 0, sizeof(dp));
		int num0 = 0;
		int num1 = 0;
		for (char c : strs[0]){
			if (c == '0')
				num0++;
			else
				num1++;
		}
		//cout<<"init"<<endl;
		for (int i = num0; i <= m; i++){
			for (int j = num1; j <= n; j++){
				dp[0][i][j] = 1;
			}
		}
		//cout<<"start"<<endl;
		for (int i = 1; i < strs.size(); i++){
			num0 = 0;
			num1 = 0;
			for (char c : strs[i]){
				if (c == '0')
					num0++;
				else
					num1++;
			}
			//cout<<i<<endl;
			for (int j = 0; j <= m; j++){
				for (int k = 0; k <= n; k++){
					if (j >= num0 && k >= num1)
						dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - num0][k - num1]);
					else
						dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
		return dp[strs.size() - 1][m][n];
	}
};