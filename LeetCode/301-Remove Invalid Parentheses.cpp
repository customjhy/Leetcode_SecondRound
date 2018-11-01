#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		dfs(s, res, 0, 0, vector<char>{'(', ')'});
		return res;
	}

	void dfs(string str, vector<string>& res, int last_i, int last_j, vector<char> ch){
		for (int cnt = 0, i = last_i; i < str.length(); i++){
			if (str[i] == ch[0])cnt++;
			if (str[i] == ch[1])cnt--;
			if (cnt >= 0)continue;
			for (int j = last_j; j <= i; j++){
				if (str[j] == ch[1] && (j == last_j || str[j - 1] != ch[1])){
					dfs(str.substr(0, j) + str.substr(j + 1, str.length() - j - 1), res, i, j, ch);
				}
			}
			return;
		}
		string temp(str.begin(), str.end());
		reverse(temp.begin(), temp.end());
		if (ch[0] == '(')
			dfs(temp, res, 0, 0, vector<char>{')', '('});
		else
			res.push_back(temp);
	}
};