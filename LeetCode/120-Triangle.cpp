#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty())
			return 0;
		if (triangle.size() == 1){
			return triangle[0][0];
		}
		vector<int> pre(1, triangle[0][0]);
		for (int i = 1; i < triangle.size(); i++){
			vector<int> cur(triangle[i].size(), INT_MAX);
			cur[0] = pre[0] + triangle[i][0];
			cur[triangle[i].size() - 1] = pre[triangle[i].size() - 2] + triangle[i][triangle[i].size() - 1];
			for (int j = 1; j < triangle[i].size() - 1; j++){
				cur[j] = min(pre[j - 1], pre[j]) + triangle[i][j];
			}
			pre = cur;
		}
		int minn = INT_MAX;
		for (int i = 0; i < pre.size(); i++){
			minn = min(minn, pre[i]);
		}
		return minn;
	}
};