#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	static bool cmp(const pair<int, int>& a, const pair<int, int>& b){
		return a.second > b.second;
	}

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> unmap;
		for (int num : nums){
			unmap[num]++;
		}
		vector<pair<int, int>> vec;
		for (unordered_map<int, int>::iterator iter = unmap.begin(); iter != unmap.end(); iter++){
			vec.push_back(make_pair(iter->first, iter->second));
		}
		sort(vec.begin(), vec.end(), cmp);
		vector<int> res;
		for (int i = 0; i < k; i++){
			res.push_back(vec[i].first);
		}
		return res;
	}
};