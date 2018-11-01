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

class Solution {
public:
	double new21Game(int N, int K, int W) {
		vector<double> dp(N + 1, 0);
		dp[0] = 1;
		double sum = 1;
		int left = 0;
		int right = 0;
		for (int i = 1; i <= K; i++){
			while (right + 1 < i){
				sum += dp[++right];
			}
			while (left < i - W){
				sum -= dp[left++];
			}
			dp[i] = sum / W;
		}
		double res = dp[K];
		for (int i = K + 1; i <= N; i++){
			while (left < i - W)
				sum -= dp[left++];
			dp[i] = sum / W;
			res += dp[i];
		}
		return res;
	}
};

//int main(){
//	int N = 21;
//	int K = 17;
//	int W = 10;
//	cout << (new Solution())->new21Game(N, K, W) << endl;
//
//	system("Pause");
//	return 0;
//}