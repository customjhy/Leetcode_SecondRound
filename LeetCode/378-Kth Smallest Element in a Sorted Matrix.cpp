#include<queue>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		static vector<vector<int>> M;
		M.clear();
		M = matrix;
		struct cmp{
			bool operator() (const pair<int, int>& a, const pair<int, int>& b){
				return M[a.first][a.second] > M[b.first][b.second];
			}
		};
		priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
		int size = M.size();
		for (int i = 0; i < size; i++){
			q.push(make_pair(i, 0));
		}
		pair<int, int> temp;
		for (int i = 0; i < k - 1; i++){
			temp = q.top();
			q.pop();
			if (temp.second == size - 1)
				continue;
			q.push(make_pair(temp.first, temp.second + 1));
		}
		temp = q.top();
		return M[temp.first][temp.second];
	}
};
//
//int main(){
//	vector<vector<int>> matrix;
//	vector<int> vec;
//	vec.push_back(-5);
//	matrix.push_back(vec);
//	Solution *solu = new Solution();
//	cout << solu->kthSmallest(matrix, 1) << endl;
//	system("Pause");
//	return 0;
//}