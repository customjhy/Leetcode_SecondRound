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
	typedef pair<int, int> ii;

	static bool cmp(ii& p1, ii& p2){
		if (p1.first == p2.first)
			return p1.second < p2.second;
		return p1.first < p2.first;
	}

	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		if (envelopes.empty())
			return 0;
		sort(envelopes.begin(), envelopes.end(), cmp);
		int n = envelopes.size();
		vector<int> dp(n, 1);
		int res = 1;
		for (int i = 1; i < n; i++){
			for (int j = i - 1; j >= 0; j--){
				if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
					dp[i] = max(dp[i], dp[j] + 1);
					res = max(dp[i], res);
				}
			}
		}
		return res;
	}
};