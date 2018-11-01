#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

class Solution {
public:
	bool valid(int count[]){
		for (int i = 0; i < 26; i++){
			if (count[i] != 0)
				return false;
		}
		return true;
	}

	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if (s.length() < p.length()){
			return res;
		}
		int count[26] = { 0 };
		int len = p.length();
		for (int i = 0; i < len; i++){
			count[p[i] - 'a']--;
		}
		int temp = s.length() - p.length();
		for (int i = s.length() - 1; i >= temp; i--){
			count[(int)(s[i] - 'a')]++;
		}
		cout << "NO" << endl;
		if (valid(count))
			res.push_back(s.length() - len);
		for (int i = s.length() - len - 1; i >= 0; i--){
			count[s[i] - 'a']++;
			count[s[i + len] - 'a']--;
			if (valid(count)){
				res.push_back(i);
			}
		}
		return res;
	}
};
//
//int main(){
//	string s = "aa";
//	string t = "bb";
//	Solution *solu = new Solution();
//	vector<int> res = solu->findAnagrams(s, t);
//	for (int i = 0; i < res.size(); i++){
//		cout << res[i] << endl;
//	}
//	system("pause");
//	return 0;
//}