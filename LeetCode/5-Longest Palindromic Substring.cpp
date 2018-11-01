#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty() || s.size() == 1)return s;
		int n = s.size();
		bool **dp = new bool*[n]; //开辟行  
		for (int i = 0; i < n; i++)
			dp[i] = new bool[n]; //开辟列
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				dp[i][j] = false;
			}
		}
		string res;
		for (int i = n - 1; i >= 0; i--){
			for (int j = i; j < n; j++){
				if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])){
					dp[i][j] = true;
				}
				if (dp[i][j] && j - i + 1 >= res.size()){
					res = s.substr(i, j - i + 1);
				}
			}
		}
		return res;
	}
};

//int main(){
//	string s("jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel");
//	Solution solu;
//	string temp = solu.longestPalindrome(s);
//	cout << temp;
//	system("Pause");
//	//"sknks"
//}