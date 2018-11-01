#include<vector>
#include<unordered_map>
#include<cstring>
#include<string>

using namespace std;

class Solution {
public:
	unordered_map<string, int> split(string str, string s){
		unordered_map<string, int> res;
		str += s;
		int pos = 0;
		while (pos < str.length()){
			int temp = str.find(s, pos);
			string t = str.substr(pos, temp - pos);
			if (!t.empty())
				res[t]++;
			pos = temp + s.length();
		}
		return res;
	}

	vector<string> uncommonFromSentences(string A, string B) {
		unordered_map<string, int> a = split(A, " ");
		unordered_map<string, int> b = split(B, " ");
		vector<string> res;
		unordered_map<string, int> m(a.begin(), a.end());
		for (unordered_map<string, int>::iterator iter = b.begin(); iter != b.end(); iter++){
			m[iter->first] += iter->second;
		}
		for (unordered_map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++){
			if (iter->second == 1)
				res.push_back(iter->first);
		}
		return res;
	}
};