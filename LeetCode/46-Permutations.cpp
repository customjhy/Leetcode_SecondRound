#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int size = nums.size();
		vector<bool> visit(size, false);
		vector<int> cur;
		vector<vector<int>> res;
		backtrace(res, visit, cur, nums);
		return res;
	}

	void backtrace(vector<vector<int>>& res, vector<bool>& visit, vector<int>& cur, vector<int>& nums){
		if (cur.size() == nums.size()){
			res.push_back(vector<int>(cur.begin(), cur.end()));
			return;
		}
		for (int i = 0; i < nums.size(); i++){
			if (visit[i])
				continue;
			visit[i] = true;
			cur.push_back(nums[i]);
			backtrace(res, visit, cur, nums);
			cur.pop_back();
			visit[i] = false;
		}
	}
};