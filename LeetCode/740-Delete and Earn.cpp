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
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++){
			m[nums[i]]++;
		}
		vector<pair<int, int>> vec;
		for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++){
			vec.push_back(make_pair(iter->first, iter->second));
		}
		vector<int> dp(vec.size() + 1, 0);
		dp[1] = vec[0].first * vec[0].second;
		for (int i = 2; i < dp.size(); i++){
			if (vec[i - 2].first + 1 == vec[i - 1].first){
				dp[i] = max(dp[i - 1], dp[i - 2] + vec[i - 1].first * vec[i - 1].second);
			}
			else{
				dp[i] = dp[i - 1] + vec[i - 1].first * vec[i - 1].second;
			}
		}
		return dp[vec.size()];
	}
};