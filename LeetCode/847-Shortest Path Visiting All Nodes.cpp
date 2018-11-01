#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

//Solution1 : AC
//class Solution {
//public:
//	void dij(vector<vector<int>>& graph, vector<vector<int>>& path, int start){
//		queue<int> q;
//		int step = 0;
//		int temp = 0;
//		q.push(start);
//		while (!q.empty()){
//			int size = q.size();
//			while (size-- > 0){
//				temp = q.front();
//				q.pop();
//				if (path[start][temp] != -1)
//					continue;
//				path[start][temp] = step;
//				for (int i = 0; i < graph[temp].size(); i++){
//					if (path[start][graph[temp][i]] != -1)
//						continue;
//					q.push(graph[temp][i]);
//				}
//			}
//			step++;
//		}
//	}
//
//	int dfs(vector<vector<int>>& graph, vector<vector<int> >& path, vector<bool>& visit, int cur, int count){
//		if (count == visit.size())
//			return 0;
//		int size = visit.size();
//		int res = INT_MAX;
//		int mindegree = INT_MAX;
//		int index = 0;
//		for (int i = 0; i < size; i++){
//			if (i != cur && !visit[i] && path[cur][i] <= res){
//				if (path[cur][i] < res){
//					res = path[cur][i];
//					mindegree = graph[i].size();
//					index = i;
//				}
//				else{
//					if (graph[i].size() < mindegree){
//						mindegree = graph[i].size();
//						index = i;
//					}
//				}
//			}
//		}
//		visit[index] = true;
//		return res + dfs(graph, path, visit, index, count + 1);
//	}
//
//	int shortestPathLength(vector<vector<int>>& graph) {
//		int size = graph.size();
//		vector<vector<int> > path(size, vector<int>(size, -1));
//		for (int i = 0; i < size; i++){
//			dij(graph, path, i);
//		}
//		//for(int i = 0;i < size;i++){
//		//for(int j = 0;j < size;j++){
//		//cout<<path[i][j]<<"\t";
//		//}
//		//cout<<endl;
//		//}
//		vector<bool> visit(size, false);
//		int res = INT_MAX;
//		for (int i = 0; i < size; i++){
//			for (int j = 0; j < size; j++)
//				visit[j] = false;
//			visit[i] = true;
//			res = min(res, dfs(graph, path, visit, i, 1));
//		}
//		return res;
//	}
//};

//Solution2 : BFS
class Solution {
public:
	typedef pair<int, int> ii;

	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> dp(n, vector<int>(1 << n, -1));
		queue<ii> Q;
		for (int i = 0; i < n; i++){
			dp[i][1 << i] = 0;
			Q.push({ i, 1 << i });
		}
		while (!Q.empty()){
			int s = Q.front().first;
			int mask = Q.front().second;
			Q.pop();
			for (int v : graph[s]){
				int next_mask = mask | (1 << v);
				if (dp[v][next_mask] != -1)
					continue;
				Q.push({ v, next_mask });
				dp[v][next_mask] = dp[s][mask] + 1;
			}
		}
		int res = INT_MAX;
		for (int i = 0; i < n; i++){
			if (dp[i][(1 << n) - 1] < 0)
				continue;
			res = min(res, dp[i][(1 << n) - 1]);
		}
		return res;
	}
};


//{ { 1 }, { 0, 2, 4 }, { 1, 3, 4 }, { 2 }, { 1, 2 } }
//int main(){
//	vector<vector<int>> graph{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, { 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, { 0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11 }, { 0, 1, 2, 3, 5, 6, 7, 8, 9, 10, 11 }, { 0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11 }, { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11 }, { 0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11 }, { 0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11 }, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11 }, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 }, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } };
//	cout << (new Solution())->shortestPathLength(graph) << endl;
//
//	system("Pause");
//	return 0;
//}