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
	vector<int> sum;
	vector<vector<vector<double>>> dp;
	int n;
	const double exp = 1e-6;

	double DP(int l, int r, int k){
		if (l > r)
			return 0;
		if (k == 0)
			return -1;
		if (abs(dp[l][r][k] + 1) > exp){
			return dp[l][r][k];
		}
		double res = 0;
		if (r - l + 1 <= k){
			res = sum[r + 1] - sum[l];
		}
		else{
			res = (sum[r + 1] - sum[l]) * 1.0 / (r - l + 1);
			for (int i = l; i < r; i++){
				if (abs(DP(l, i, k - 1) + 1) > exp)
					res = max(res, DP(l, i, k - 1) + ((sum[r + 1] - sum[i + 1]) * 1.0 / (r - i)));
			}
		}
		//cout << l << "\t" << r << "\t" <<k<<"\t" <<res << endl;
		dp[l][r][k] = res;
		return res;
	}

	double largestSumOfAverages(vector<int>& A, int K) {
		n = A.size();
		dp = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(K + 1, -1)));
		sum = vector<int>(n + 1, 0);
		for (int i = 1; i <= n; i++){
			sum[i] = sum[i - 1] + A[i - 1];
		}
		/*DP(0, n - 1, K);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cout << DP(i,j,K) << "\t";
			}
			cout << endl;
		}*/
		return DP(0, n - 1, K);
	}
};
//
//int main(){
//	vector<int> A{ 1, 2, 3, 4, 5, 6, 7 };
//	int K = 4;
//	cout << (new Solution())->largestSumOfAverages(A, K) << endl;
//
//	system("Pause");
//	return 0;
//}

