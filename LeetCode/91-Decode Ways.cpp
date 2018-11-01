#include<cstring>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		if (s[0] == '0')
			return 0;
		int len = s.length();
		vector<int> dp(len + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= len; i++){
			if (s[i - 1] == '0'){
				if (s[i - 2] == '1' || s[i - 2] == '2'){
					dp[i] = dp[i - 2];
					continue;
				}
				else{
					return 0;
				}
			}
			dp[i] = dp[i - 1];
			if (stoi(s.substr(i - 2, 2)) <= 26 && stoi(s.substr(i - 2, 2)) > 10){
				dp[i] += dp[i - 2];
			}
		}
		return dp[len];
	}
};
