#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() <= 1)
			return 0;
		int left = 0;
		int right = height.size() - 1;
		int res = 0;
		while (left < right){
			int h = min(height[left], height[right]);
			res = max(h * (right - left), res);
			while (left < right && height[left] <= h)left++;
			while (left < right && height[right] <= h)right--;
		}
		return res;
	}
};