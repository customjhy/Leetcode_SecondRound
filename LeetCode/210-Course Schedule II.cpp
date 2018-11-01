#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> vec(numCourses, 0);
		unordered_map<int, unordered_set<int>> Map;
		for (auto pre : prerequisites){
			vec[pre.first]++;
			if (Map.find(pre.second) == Map.end()){
				unordered_set<int> Set;
				Set.insert(pre.first);
				Map[pre.second] = Set;
			}
			else{
				Map[pre.second].insert(pre.first);
			}
		}
		queue<int> que;
		int count = numCourses;
		vector<int> res;
		for (int i = 0; i < numCourses; i++){
			if (vec[i] == 0){
				que.push(i);
			}
		}
		while (!que.empty()){
			int cur = que.front();
			que.pop();
			res.push_back(cur);
			count--;
			for (unordered_set<int>::iterator iter = Map[cur].begin(); iter != Map[cur].end(); iter++){
				vec[*iter]--;
				if (vec[*iter] == 0){
					que.push(*iter);
				}
			}
		}
		if (count == 0){
			res.clear();
		}
		return res;
	}
};