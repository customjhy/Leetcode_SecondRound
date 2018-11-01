#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0)return 0;
		set<char> charSet;
		int left = 0;
		int res = 1;
		charSet.insert(s[0]);
		for (int right = 1; right < s.length(); right++){
			while (charSet.count(s[right]) == 1){
				charSet.erase(s[left++]);
			}
			charSet.insert(s[right]);
			res = max(res, (int)charSet.size());
		}
		return res;
	}
};
//
//int main(){
//	string s("123");
//	for (int i = 0; i < s.length(); i++){
//		cout << s[i];
//	}
//	system("Pause");
//}