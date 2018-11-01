#include<vector>
#include<string>
#include<cstring>
#include<set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.length(), false);
		set<string> word;
		for (int i = 0; i < wordDict.size(); i++){
			word.insert(wordDict[i]);
		}
		for (int i = 0; i < s.length(); i++){
			for (int j = i - 1; j >= 0; j--){
				if (dp[j] && word.find(s.substr(j + 1, i - j)) != word.end()){
					dp[i] = true;
					break;
				}
			}
			if (dp[i])
				continue;
			if (word.find(s.substr(0, i + 1)) != word.end()){
				dp[i] = true;
			}
		}
		return dp[s.size() - 1];
	}
};