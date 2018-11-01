#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		vector<int> left(len, 0);
		vector<int> right(len, 0);
		left[0] = height[0];
		for (int i = 1; i < len; i++){
			left[i] = max(left[i - 1], height[i]);
		}
		right[len - 1] = height[len - 1];
		for (int i = len - 2; i >= 0; i--){
			right[i] = max(right[i + 1], height[i]);
		}
		int res = 0;
		for (int i = 0; i < len; i++){
			res += min(right[i], left[i]) - height[i];
		}
		return res;
	}
};