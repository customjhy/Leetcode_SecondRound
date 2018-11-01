#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	string makeLargestSpecial(string S) {
		int count = 0;
		vector<string> vec;
		int j = 0;
		for (int i = 0; i < S.length(); i++){
			if (S[i] == '1')
				count++;
			else
				count--;
			if (count == 0){
				vec.push_back("1" + makeLargestSpecial(S.substr(j, i - j - 1)) + "0");
				j = i + 1;
			}
		}
		sort(vec.begin(), vec.end(), greater<string>());
		string res = "";
		for (int i = 0; i < vec.size(); i++){
			res += vec[i];
		}
		return res;
	}
};