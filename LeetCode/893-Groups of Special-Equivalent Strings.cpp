#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
#include<functional>

using namespace std;

class Solution {
public:
	string hash(string& str){
		int even[26] = { 0 };
		int odd[26] = { 0 };
		for (int i = 0; i < str.length(); i++){
			if (i % 2){
				odd[str[i] - 'a']++;
			}
			else{
				even[str[i] - 'a']++;
			}
		}
		string res = "";
		for (int i = 0; i < 26; i++){
			if (odd[i]){
				res += to_string(odd[i]) + (char)('a' + i);
			}
		}
		res += "#";
		for (int i = 0; i < 26; i++){
			if (even[i]){
				res += to_string(even[i]) + (char)('a' + i);
			}
		}
		return res;
	}

	int numSpecialEquivGroups(vector<string>& A) {
		if (A.size() == 0)
			return 0;
		unordered_set<string> s;
		string temp = "";
		for (int i = 0; i < A.size(); i++){
			temp = hash(A[i]);
			if (s.find(temp) == s.end()){
				s.insert(temp);
			}
		}
		return s.size();
	}
};