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
	bool dfs(vector<string>& res, unordered_map<string, vector<string>>& m, string start, int count){
		if (count == 0)
			return true;
		for (int i = 0; i < m[start].size(); i++){
			string cur = m[start][i];
			res.push_back(cur);
			m[start].erase(m[start].begin() + i);
			if (dfs(res, m, cur, count - 1))
				return true;
			m[start].insert(m[start].begin() + i, cur);
			res.pop_back();
		}
		return false;
	}

	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, vector<string>> m;
		for (auto iter : tickets){
			if (m.find(iter.first) != m.end()){
				m[iter.first].push_back(iter.second);
			}
			else{
				vector<string> temp{ iter.second };
				m[iter.first] = temp;
			}
		}
		for (unordered_map<string, vector<string>>::iterator iter = m.begin(); iter != m.end(); iter++){
			sort(iter->second.begin(), iter->second.end());
		}
		vector<string> res{ "JFK" };
		string start = "JFK";
		int count = tickets.size();
		dfs(res, m, start, count);
		return res;
	}
};