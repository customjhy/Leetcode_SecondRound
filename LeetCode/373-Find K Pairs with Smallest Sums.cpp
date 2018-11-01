#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<functional>

using namespace std;

class Solution {
public:
	struct cmp{
		bool operator() (pair<int,int>& p1, pair<int,int>& p2){
			return p1.first + p1.second > p2.first + p2.second;
		}
	};

	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (int i = 0; i < k && i < nums1.size(); i++){
			for (int j = 0; j < k && j < nums2.size(); j++){
				pq.push(make_pair(nums1[i], nums2[j]));
			}
		}
		vector<pair<int, int>> res;
		while (k-- > 0){
			res.push_back(pq.top());
			pq.pop();
		}
		return res;
	}
};