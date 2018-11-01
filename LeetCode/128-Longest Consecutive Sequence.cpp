#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> m;
		int res = 0;
		for (int num : nums){
			if (m.find(num) == m.end()){
				int left = m[num - 1];
				int right = m[num + 1];
				int sum = left + right + 1;
				m[num] = sum;
				m[num - left] = sum;
				m[num + right] = sum;
				res = max(res, sum);
			}
			else{
				continue;
			}
		}
		return res;
	}
};