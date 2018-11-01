#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<math.h>
#include<unordered_map>
#include<queue>
#include<set>

using namespace std;

//class Solution {
//public:
//	bool compare(string& str1, string& str2){
//		bool flag = false;
//		for (int i = 0; i < str1.length(); i++){
//			if (str1[i] != str2[i]){
//				if (flag){
//					return false;
//				}
//				else{
//					flag = true;
//				}
//			}
//		}
//		return flag;
//	}
//
//	int dfs(string beginWord, string endWord, vector<bool> visit, unordered_map<string, int> m, unordered_map<string, int> words){
//		if (beginWord == endWord)
//			return 1;
//		if (m.count(beginWord) == 1){
//			return m[beginWord];
//		}
//		int res = INT_MAX;
//		string temp = beginWord;
//		for (int i = 0; i < temp.length(); i++){
//			for (char c = 'a'; c <= 'z'; c++){
//				temp[i] = c;
//				if (temp != beginWord && words.count(temp) == 1){
//					int j = words[temp];
//					if (!visit[j]){
//						visit[j] = true;
//						int tempRes = dfs(temp, endWord, visit, m, words);
//						if (tempRes != INT_MAX && tempRes + 1 < res)
//							res = tempRes + 1;
//						visit[j] = false;
//					}
//				}
//			}
//			temp[i] = beginWord[i];
//		}
//		m[beginWord] = res;
//		return res;
//	}
//
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		int size = wordList.size();
//		vector<bool> visit(size, false);
//		unordered_map<string, int> m;
//		unordered_map<string, int> words;
//		for (int i = 0; i < wordList.size(); i++){
//			words[wordList[i]] = i;
//		}
//		int res = dfs(beginWord, endWord, visit, m, words);
//		return res == INT_MAX ? 0 : res;
//	}
//};


class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (beginWord == endWord)
			return 0;
		queue<string> q;
		set<string> s;
		for (string word : wordList){
			s.insert(word);
		}
		if (s.find(endWord) == s.end())
			return 0;
		int level = 1;
		q.push(beginWord);
		while (!q.empty()){
			int size = q.size();
			while (size-- > 0){
				string begin = q.front();
				q.pop();
				if (begin.compare(endWord) == 0)
					return level;
				for (int i = 0; i < begin.size(); i++){
					char c = begin[i];
					for (char j = 'a'; j <= 'z'; j++){
						begin[i] = j;
						if (s.find(begin) != s.end()){
							q.push(begin);
							s.erase(begin);
						}
					}
					begin[i] = c;
				}
			}
			level++;
		}
		return 0;
	}
};