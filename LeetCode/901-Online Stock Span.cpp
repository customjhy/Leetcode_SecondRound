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

class StockSpanner {
public:
	vector<int> nums;
	vector<int> dp;

	StockSpanner() {

	}

	int next(int price) {
		int res = 1;
		int index = nums.size() - 1;
		while (index >= 0){
			if (price >= nums[index]){
				res += dp[index];
				index -= dp[index];
			}
			else
				break;
		}
		nums.push_back(price);
		dp.push_back(res);
		return res;
	}
};

/**
* Your StockSpanner object will be instantiated and called as such:
* StockSpanner obj = new StockSpanner();
* int param_1 = obj.next(price);
*/