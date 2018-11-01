#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> edge(numCourses);
		unordered_map<int, int> m;
		for (pair<int, int> pre : prerequisites){
			edge[pre.second].push_back(pre.first);
			m[pre.first]++;
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++){
			if (m.find(i) == m.end() || m[i] == 0){
				q.push(i);
			}
		}
		while (!q.empty()){
			int temp = q.front();
			q.pop();
			for (int i = 0; i < edge[temp].size(); i++){
				m[edge[temp][i]]--;
				if (m[edge[temp][i]] == 0){
					q.push(edge[temp][i]);
				}
			}
		}
		for (int i = 0; i < numCourses; i++){
			if (m.find(i) != m.end() && m[i] > 0)
				return false;
		}
		return true;
	}
};