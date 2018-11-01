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
	vector<vector<int>> dp;
	int n;
	string str;

	int DP(int l, int r){
		if (l > r)
			return 0;
		if (dp[l][r] != -1)
			return dp[l][r];
		//cout<<l<<"\t"<<r<<"\t"<<k<<endl;
		while (r > l && str[r] == str[r - 1]){
			r--;
		}
		int res = DP(l, r - 1) + 1;
		for (int i = l; i < r; i++){
			if (str[i] == str[r]){
				res = min(res, DP(l, i) + DP(i + 1, r - 1));
			}
		}
		dp[l][r] = res;
		return res;
	}

	int strangePrinter(string s) {
		n = s.length();
		str = s;
		if (n <= 1)
			return n;
		dp = vector<vector<int>>(n, vector<int>(n, -1));
		return DP(0, n - 1);
	}
};