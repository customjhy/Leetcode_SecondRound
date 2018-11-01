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
	vector<vector<vector<int>>> dp;
	int m, n;
	const int mod = 1000000007;

	int DP(int i, int j, int step){
		if (i < 0 || i >= m || j < 0 || j >= n)
			return 1;
		if (step == 0)
			return 0;
		//cout<<"mn\t"<<m<<"\t"<<n<<endl;
		//cout<<i<<"\t"<<j<<"\t"<<step<<endl;
		if (dp[i][j][step] != -1)
			return dp[i][j][step];
		//cout<<i<<"\t"<<j<<"\t"<<step<<endl;
		int dir[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
		int res = 0;
		for (int k = 0; k < 4; k++){
			int r = i + dir[k][0];
			int c = j + dir[k][1];
			res += DP(r, c, step - 1);
			res %= mod;
			//cout<<r<<"\t"<<c<<"\t"<<step - 1<<"\t"<<DP(r, c, step - 1)<<endl;
		}
		dp[i][j][step] = res;
		return res;
	}

	int findPaths(int m, int n, int N, int i, int j) {
		dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(N + 1, -1)));
		this->m = m;
		this->n = n;
		/*DP(i, j, N);
		for(int i= 0;i < m;i++){
		for(int j = 0;j < n;j++){
		cout<<dp[i][j][N - 1]<<"\t";
		}
		cout<<endl;
		}*/
		return DP(i, j, N);
	}
};