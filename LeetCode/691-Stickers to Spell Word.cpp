#include<iostream>
#include<cstdio>
#include<stdio.h>
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
	unordered_map<string, int> m;

	string encode(vector<int>& need){
		string res = "";
		for (int i = 0; i < 26; i++){
			if (need[i] <= 0)
				res += "0#";
			else
				res += to_string(need[i]) + "#";
		}
		return res;
	}

	int dfs(vector<vector<int>>& cnt, vector<int>& need){
		string str = encode(need);
		if (m.find(str) != m.end())
			return m[str];
		int res = INT_MAX;
		for (int i = 0; i < cnt.size(); i++){
			bool flag = true;
			for (int j = 0; j < 26; j++){
				if (need[j] > 0 && cnt[i][j] > 0){
					flag = false;
					break;
				}
			}
			if (!flag){
				for (int j = 0; j < 26; j++)
					need[j] -= cnt[i][j];
				int ans = dfs(cnt, need);
				if (ans != INT_MAX)
					res = min(res, 1 + ans);
				for (int j = 0; j < 26; j++)
					need[j] += cnt[i][j];
			}
		}
		m[str] = res;
		return res;
	}

	int minStickers(vector<string>& stickers, string target) {
		int n = stickers.size();
		vector<vector<int>> cnt(n, vector<int>(26, 0));
		vector<int> tot(26, 0);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < stickers[i].length(); j++){
				cnt[i][stickers[i][j] - 'a']++;
				tot[stickers[i][j] - 'a']++;
			}
		}
		vector<int> need(26, 0);
		m[encode(need)] = 0;
		for (int i = 0; i < target.length(); i++){
			need[target[i] - 'a']++;
			if (tot[target[i] - 'a'] == 0)
				return -1;
		}
		int res = dfs(cnt, need);
		return  res == INT_MAX ? -1 : res;
	}
};