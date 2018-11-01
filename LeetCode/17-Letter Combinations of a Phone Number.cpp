#include<vector>
#include<string>
#include<cstring>

using namespace std;

class Solution {
public:
	void backtrace(vector<string>& res, string& temp, const string& digits, int start, string mapping[]){
		if (start == digits.length()){
			string str(temp);
			res.push_back(str);
			return;
		}
		for (char c : mapping[digits[start] - '0']){
			temp = temp + c;
			backtrace(res, temp, digits, start + 1, mapping);
			temp.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty())
			return res;
		string temp = "";
		string mapping[] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		backtrace(res, temp, digits, 0, mapping);
		return res;
	}
};