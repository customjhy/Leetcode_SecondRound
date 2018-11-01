#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
		vector<vector<double>> workers;
		for (int i = 0; i < quality.size(); i++){
			workers.push_back({ (double)(wage[i]) / quality[i], (double)quality[i] });
		}
		sort(workers.begin(), workers.end());
		priority_queue<double> pq;
		double res = DBL_MAX;
		double sum = 0;
		for (auto worker : workers){
			sum += worker[1];
			pq.push(worker[1]);
			if (pq.size() > K){
				sum -= pq.top();
				pq.pop();
			}
			if (pq.size() == K){
				res = min(res, sum * worker[0]);
			}
		}
		return res;
	}
};