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

//Solution1 : TLE
//class Solution {
//public:
//	map<string, int> m;
//
//	int help(vector<int>& boxes,string str){
//		if (m.find(str) != m.end())
//			return m[str];
//		int res = 0;
//		int index = 0;
//		while (index < boxes.size()){
//			if (str[index] == '1'){
//				index++;
//				continue;
//			}
//			int num = boxes[index];
//			string next = str;
//			int cnt = 0;
//			while (index < boxes.size() && !(next[index] == '0' && boxes[index] != num)){
//				if (next[index] == '0'){
//					cnt++;
//					next[index] = '1';
//				}
//				index++;
//			}
//			res = max(res, cnt * cnt + help(boxes, next));
//		}
//		m[str] = res;
//		return res;
//	}
//
//	int removeBoxes(vector<int>& boxes) {
//		int n = boxes.size();
//		string str(n, '0');
//		return help(boxes, str);
//	}
//};

class Solution {
public:
	int help(vector<int>& boxes, vector<vector<vector<int>>>& dp, int l, int r, int k){
		if (l > r)
			return 0;
		if (l == r)
			return (k + 1) * (k + 1);
		if (dp[l][r][k] != -1)
			return dp[l][r][k];
		while (r > l && boxes[r] == boxes[r - 1]){
			r--;
			k++;
		}
		int res = help(boxes, dp, l, r - 1, 0) + (k + 1) * (k + 1);
		for (int i = l; i < r; i++){
			if (boxes[i] == boxes[r]){
				res = max(res, help(boxes, dp, i + 1, r - 1, 0) + help(boxes, dp, l, i, k + 1));
			}
		}
		dp[l][r][k] = res;
		return res;
	}

	int removeBoxes(vector<int>& boxes) {
		int n = boxes.size();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
		return help(boxes, dp, 0, n - 1, 0);
	}
};