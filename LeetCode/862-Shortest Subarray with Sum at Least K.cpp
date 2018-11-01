#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

//Solution1 : prefix Sum O(n^2)
//class Solution {
//public:
//	typedef long long ll;
//
//	int shortestSubarray(vector<int>& A, int K) {
//		if (K <= 0)return 0;
//		vector<ll> sum(A.size() + 1, 0);
//		for (int i = 1; i < sum.size(); i++){
//			sum[i] = sum[i - 1] + A[i - 1];
//		}
//		int n = A.size();
//		int res = INT_MAX;
//		for (int i = 0; i < n; i++){
//			for (int j = i + 1; j <= n; j++){
//				if (sum[j] - sum[i] >= K){
//					res = min(res, j - i);
//				}
//			}
//		}
//		return res == INT_MAX ? -1 : res;
//	}
//};


//Solution2: prefix Sum and deque O(n)
class Solution {
public:
	int shortestSubarray(vector<int>& A, int K) {
		int res = INT_MAX;
		int n = A.size();
		vector<int> sum(n + 1, 0);
		for (int i = 1; i <= n; i++){
			sum[i] = sum[i - 1] + A[i - 1];
		}
		deque<int> dq;
		for (int i = 0; i <= n; i++){
			while (!dq.empty() && sum[i] - sum[dq.front()] >= K){
				res = min(res, i - dq.front());
				dq.pop_front();
			}
			while (!dq.empty() && sum[i] <= sum[dq.back()]){
				dq.pop_back();
			}
			dq.push_back(i);
		}
		return res == INT_MAX ? -1 : res;
	}
};