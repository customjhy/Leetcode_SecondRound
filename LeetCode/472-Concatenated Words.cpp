#include<iostream>
#include<cstdio>
#include<stdio.h>
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
	unordered_set<string> res;
	unordered_set<string> S;

	bool valid(string str){
		if (res.find(str) != res.end())
			return true;
		for (int i = 1; i < str.length(); i++){
			if (S.find(str.substr(0, i)) != S.end()){
				if (S.find(str.substr(i)) != S.end() || valid(str.substr(i))){
					//res.insert(str);
					return true;
				}
			}
		}
		return false;
	}

	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		if (words.size() <= 2)
			return vector<string>();
		S.insert(words.begin(), words.end());
		for (string& word : words){
			if (valid(word)){
				res.insert(word);
			}
		}
		return vector<string>(res.begin(), res.end());
	}
};