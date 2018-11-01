#include<string>
#include<queue>

using namespace std;

class Solution {
public:
	bool valid(const int S[], const int T[]){
		for (int i = 0; i < 128; i++){
			if (S[i] < T[i])
				return false;
		}
		return true;
	}

	string minWindow(string s, string t) {
		int countT[128] = { 0 };
		int countS[128] = { 0 };
		for (int i = 0; i < t.length(); i++){
			countT[t[i]]++;
		}
		int minLen = INT_MAX;
		string res;
		int left = 0;
		int right = 0;
		while (right < s.length()){
			while (!valid(countS, countT) && right < s.length()){
				countS[s[right++]]++;
			}
			if (!valid(countS, countT))
				break;
			while (valid(countS, countT)){
				countS[s[left++]]--;
			}
			if (right - left + 1 < minLen){
				minLen = right - left + 1;
				res = s.substr(left - 1, right - left + 1);
			}
		}
		if (minLen == INT_MAX)
			return "";
		return res;
	}
};