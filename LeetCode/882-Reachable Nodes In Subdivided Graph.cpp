#include<vector>
#include<unordered_map>
#include<queue>
#include<iostream>

using namespace std;

//class Solution {
//public:
//	int reachableNodes(vector<vector<int>>& edges, int M, int N) {
//		cout << "begin" << endl;
//		if (N == 0)
//			return 0;
//		if (M == 0)
//			return 1;
//		static vector<int> maxWeight(N, 0);
//		struct cmp
//		{
//			bool operator() (const int& i, const int& j){
//				return maxWeight[i] < maxWeight[j];
//			}
//		};
//
//		vector<vector<int> > edge(N);
//		unordered_map<int, unordered_map<int, int>> weight;
//		priority_queue<int, vector<int>, cmp> pq;
//		for (vector<int> e : edges){
//			edge[e[0]].push_back(e[1]);
//			edge[e[1]].push_back(e[0]);
//			weight[e[0]][e[1]] = e[2];
//			weight[e[1]][e[0]] = e[2];
//		}
//		cout << "initial" << endl;
//		maxWeight[0] = M;
//		pq.push(0);
//		int pre = -1;
//		int cur = 0;
//		while (!pq.empty()){
//			cur = pq.top();
//			pq.pop();
//			if (cur == pre)
//				continue;
//			int w = maxWeight[cur];
//			for (int i = 0; i < edge[cur].size(); i++){
//				int node = edge[cur][i];
//				if (w - weight[cur][node] - 1 > maxWeight[node]){
//					maxWeight[node] = w - weight[cur][node] - 1;
//					pq.push(node);
//				}
//			}
//			pre = cur;
//			cout << "cur:" << cur << endl;
//		}
//		cout << "pq ok" << endl;
//		int res = 0;
//		for (int i = 0; i < N; i++){
//			if (maxWeight[i] > 0)
//				res++;
//		}
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < edge[i].size(); j++){
//				int node = edge[i][j];
//				if (i > node)
//					continue;
//				res += min(weight[i][node], maxWeight[i] + maxWeight[node]);
//			}
//		}
//		cout << "res ok" << endl;
//		cout << res << endl;
//		return res;
//	}
//};


class Solution {
public:
	struct cmp
	{
		bool operator() (pair<int, int> i, pair<int, int> j){
			if (i.first == j.first)
				return i.second > j.second;
			return i.first < j.first;
		}
	};

	int reachableNodes(vector<vector<int>>& edges, int M, int N) {
		if (N == 0)
			return 0;
		if (M == 0)
			return 1;
		vector<int> maxWeight(N, -1);
		vector<vector<int> > edge(N);
		vector<bool> visit(N, false);
		unordered_map<int, unordered_map<int, int> > weight;
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (vector<int> e : edges){
			edge[e[0]].push_back(e[1]);
			edge[e[1]].push_back(e[0]);
			weight[e[0]][e[1]] = e[2];
			weight[e[1]][e[0]] = e[2];
		}
		maxWeight[0] = M;
		pq.push(make_pair(maxWeight[0], 0));
		int cur = 0;
		while (!pq.empty()){
			cur = pq.top().second;
			pq.pop();
			if (visit[cur])
				continue;
			visit[cur] = true;
			int w = maxWeight[cur];
			for (int i = 0; i < edge[cur].size(); i++){
				int node = edge[cur][i];
				if (w - weight[cur][node] - 1 > maxWeight[node] && !visit[node]){
					maxWeight[node] = w - weight[cur][node] - 1;
					pq.push(make_pair(maxWeight[node], node));
				}
			}
		}
		int res = 0;
		for (int i = 0; i < N; i++){
			if (maxWeight[i] >= 0)
				res++;
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < edge[i].size(); j++){
				int node = edge[i][j];
				if (i > node)
					continue;
				int count = 0;
				if (maxWeight[i] == -1)
					count++;
				if (maxWeight[node] == -1)
					count++;
				res += min(weight[i][node], maxWeight[i] + maxWeight[node] + count);
			}
		}
		return res;
	}
};
//
//
//int main(){
//	vector<vector<int>> edges{ { 4, 6, 11 }, { 5, 6, 2 }, { 2, 6, 11 }, { 0, 3, 19 }, { 1, 7, 21 }, { 5, 7, 1 }, { 1, 5, 4 }, { 0, 7, 12 }, { 6, 7, 3 }, { 3, 6, 22 }, { 0, 5, 24 }, { 1, 2, 8 }, { 3, 7, 11 }, { 1, 3, 14 }, { 4, 5, 7 }, { 4, 7, 14 }, { 0, 4, 5 }, { 2, 4, 7 }, { 3, 4, 11 }, { 3, 5, 15 }, { 2, 5, 13 }, { 2, 3, 6 }, { 1, 4, 6 }, { 0, 2, 3 }, { 1, 6, 20 } };
//	int M = 18;
//	int N = 8;
//	cout << (new Solution())->reachableNodes(edges, M, N) << endl;
//
//	system("Pause");
//	return 0;
//}
//
