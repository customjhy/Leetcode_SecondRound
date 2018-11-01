#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 1)return strs[0];
		if (strs.size() == 0)return "";
		int len = INT_MAX;
		for (int i = 0; i < strs.size(); i++){
			if (strs[i].size() < len)
				len = strs[i].size();
		}
		int i = 0;
		for (; i < len; i++){
			int j = 1;
			for (; j < strs.size(); j++){
				if (strs[j][i] != strs[0][i])
					break;
			}
			if (j != strs.size())
				break;
		}
		return strs[0].substr(0, i);
	}
};