#include<cstring>
#include<string>
#include<vector>
#include<string.h>

using namespace std;

class Solution {
public:
	void help(string s, int start, string cur, vector<string>& res){
		if (start == s.length()){
			res.push_back(cur);
			return;
		}
		if (s[start] >= '0' && s[start] <= '9'){
			cur += s[start];
			help(s, start + 1, cur, res);
		}
		else{
			cur += s[start];
			help(s, start + 1, cur, res);
			cur[cur.length() - 1] = s[start] - 'a' + 'A';
			help(s, start + 1, cur, res);
		}
	}

	vector<string> letterCasePermutation(string S) {
		for (int i = 0; i < S.length(); i++){
			if (S[i] >= 'A' && S[i] <= 'Z'){
				S[i] = S[i] - 'A' + 'a';
			}
		}
		vector<string> res;
		help(S, 0, "", res);
		return res;
	}
};