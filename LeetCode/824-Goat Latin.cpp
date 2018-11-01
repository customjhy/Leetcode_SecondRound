#include<cstring>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
	unordered_set<char> SET{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

	vector<string> split(string s, string p){
		vector<string> res;
		s += p;
		int pos = 0;
		while (pos < s.length()){
			int temp = s.find(p, pos);
			if (temp > pos)
				res.push_back(s.substr(pos, temp - pos));
			pos = temp + p.length();
		}
		return res;
	}

	string solve(string s){
		if (SET.find(s[0]) != SET.end()){
			return s + "ma";
		}
		else{
			return s.substr(1, s.length() - 1) + s[0] + "ma";
		}
	}

	string toGoatLatin(string S) {
		vector<string> words = split(S, " ");
		string res = "";
		int k = 1;
		for (string str : words){
			res += solve(str);
			for (int i = 0; i < k; i++){
				res += "a";
			}
			k++;
			res += " ";
		}
		return res.substr(0, res.length() - 1);
	}
};