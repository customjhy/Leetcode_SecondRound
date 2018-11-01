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
	int findSubstringInWraproundString(string p) {
		int cnt[26] = { 0 };
		int len = 0;
		int res = 0;
		for (int i = 0; i < p.length(); i++){
			int cur = p[i] - 'a';
			if (i == 0 || p[i - 1] != (cur + 25) % 26 + 'a')
				len = 0;
			if (++len > cnt[cur]){
				res += len - cnt[cur];
				cnt[cur] = len;
			}
		}
		return res;
	}
};