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
	int findMinMoves(vector<int>& machines) {
		int n = machines.size();
		int sum = 0;
		for (int m : machines){
			sum += m;
		}
		if (sum % n != 0)
			return -1;
		int avg = sum / n;
		vector<int> left(n, 0);
		left[0] = machines[0];
		for (int i = 1; i < n; i++){
			left[i] = left[i - 1] + machines[i];
		}
		vector<int> right(n, 0);
		right[n - 1] = machines[n - 1];
		for (int i = n - 2; i >= 0; i--){
			right[i] = right[i + 1] + machines[i];
		}
		int res = max(abs(left[0] - avg), abs(right[n - 1] - avg));
		for (int i = 1; i < n - 1; i++){
			int l = avg * i - left[i - 1] > 0 ? avg * i - left[i - 1] : 0;
			int r = avg * (n - i - 1) - right[i + 1] > 0 ? avg * (n - i - 1) - right[i + 1] : 0;
			res = max(l + r, res);
		}
		return res;
	}
};