#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	typedef long long ll;

	void addRect(vector<vector<int>>& vec, vector<int> rec, int start){
		if (start == vec.size()){
			vec.push_back(rec);
			return;
		}
		vector<int> cur = vec[start];
		if (rec[2] <= cur[0] || rec[0] >= cur[2] || rec[1] >= cur[3] || rec[3] <= cur[1]){
			addRect(vec, rec, start + 1);
			return;
		}
		if (rec[2] > cur[2]){
			addRect(vec, vector<int>{cur[2], rec[1], rec[2], rec[3] }, start + 1);
		}
		if (rec[0] < cur[0]){
			addRect(vec, vector<int>{rec[0], rec[1], cur[0], rec[3] }, start + 1);
		}
		if (rec[1] < cur[1]){
			addRect(vec, vector<int>{max(rec[0], cur[0]), rec[1], min(rec[2], cur[2]), cur[1] }, start + 1);
		}
		if (rec[3] > cur[3]){
			addRect(vec, vector<int>{max(rec[0], cur[0]), cur[3], min(rec[2], cur[2]), rec[3] }, start + 1);
		}
	}

	int rectangleArea(vector<vector<int>>& rectangles) {
		vector<vector<int>> vec;
		for (vector<int> rec : rectangles){
			addRect(vec, rec, 0);
		}
		int mod = 1000000007;
		ll res = 0;
		for (vector<int> rec : vec){
			res = (res + ((ll)rec[2] - (ll)rec[0]) * ((ll)rec[3] - (ll)rec[1])) % mod;
		}
		return (int)res;
	}
};