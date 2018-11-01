#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<functional>

using namespace std;

class Solution {
public:
	int help(int count[]){
		int res = 0;
		for (int i = 0; i < 26; i++){
			res = max(res, count[i]);
		}
		return res;
	}

	int characterReplacement(string s, int k) {
		if (s.empty())
			return 0;
		int left = 0;
		int right = 0;
		int count[26] = { 0 };
		count[s[0] - 'A']++;
		int res = 0;
		while (right < s.length()){
			int num = help(count);
			if (right - left + 1 - num <= k){
				res = max(res, right - left + 1);
				right++;
				count[s[right] - 'A']++;
			}
			else{
				count[s[left] - 'A']--;
				left++;
			}
		}
		return res;
	}
};