#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int count[26] = { 0 };
		for (int i = 0; i < s1.length(); i++){
			count[s1[i] - 'a']++;
			count[s2[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++){
			if (count[i] != 0)
				return false;
		}
		for (int i = 1; i <= s1.length() - 1; i++){
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			//cout<<s1.substr(0, i)<<"\t"<<s2.substr(s2.length() - i, i)<<endl;
			//cout<<s1.substr(i)<<"\t"<<s2.substr(0, s2.length() - i)<<endl;
			if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i, i)) && isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))
				return true;
		}
		return false;
	}
};