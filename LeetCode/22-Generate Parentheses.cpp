#include<set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> vec;
		backtrace(vec, "", 0, 0, n);
		return vec;
	}

	void backtrace(vector<string> vec, string str, int open, int close, int max){
		if (str.length() == 2 * max){
			vec.push_back(str);
			return;
		}
		if (open < max){
			backtrace(vec, str + "(", open + 1, close, max);
		}
		if (close < open){
			backtrace(vec, str + ")", open, close + 1, max);
		}
	}
};