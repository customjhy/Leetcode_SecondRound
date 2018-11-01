#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<functional>

using namespace std;

//Solution1 : O(n^2)
//class Solution {
//public:
//	int largestRectangleArea(vector<int>& heights) {
//		if (heights.empty())
//			return 0;
//		int res = 0;
//		for (int i = 0; i < heights.size(); i++){
//			int w = 1;
//			int h = heights[i];
//			res = max(res, w * h);
//			for (int j = i - 1; j >= 0; j--){
//				w++;
//				h = min(h, heights[j]);
//				res = max(res, w * h);
//			}
//		}
//		return res;
//	}
//};

//Solution2 : use stack O(n)
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int res = 0;
		stack<int> s;
		for (int i = 0; i <= heights.size(); i++){
			int h = (i == heights.size() ? 0 : heights[i]);
			if (s.empty() || h >= heights[s.top()]){
				s.push(i);
			}
			else{
				int index = s.top(); s.pop();
				int area = heights[index] * (s.empty() ? i : i - 1 - s.top());
				res = max(area, res);
				i--;
			}
		}
		return res;
	}
};