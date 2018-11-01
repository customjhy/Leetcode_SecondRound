#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

//class Solution {
//public:
//	int help(int K, int N, vector<vector<int>>& dp){
//		if (N <= 1)
//			return N;
//		if (K == 1){
//			return N;
//		}
//		if (dp[K][N] > 0)
//			return dp[K][N];
//		int result = N + 1;
//		int low = 1;
//		int high = N;
//		while (low < high){
//			int mid = (low + high) >> 1;
//			int left = help(K - 1, mid - 1, dp);
//			int right = help(K, N - mid, dp);
//			result = min(result, max(left, right) + 1);
//			if (left == right){
//				break;
//			}
//			else if (left < right){
//				low = mid + 1;
//			}
//			else{
//				high = mid;
//			}
//		}
//		dp[K][N] = result;
//		return result;
//	}
//
//	int superEggDrop(int K, int N) {
//		vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
//		return help(K, N, dp);
//	}
//};


//int main(){
//  //res:5
//	int K = 3;
//	int N = 25;
//	cout << (new Solution())->superEggDrop(K, N) << endl;
//
//	system("Pause");
//	return 0;
//}