#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	double solve(vector<int>& p1, vector<int>& p2, vector<int>& p3){
		return	(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] - p1[0] * p3[1] - p2[0] * p1[1] - p3[0] * p2[1]) * 1.0 / 2;
	}

	//(1 / 2)*(x1y2 * 1 + x2y3 * 1 + x3y1 * 1 - x1y3 * 1 - x2y1 * 1 - x3y2 * 1)
	
	double largestTriangleArea(vector<vector<int>>& points) {
		double res = 0;
		for (int i = 0; i < points.size(); i++){
			for (int j = i + 1; j < points.size(); j++){
				for (int k = j + 1; k < points.size(); k++){
					res = max(res, solve(points[i], points[j], points[k]));
				}
			}
		}
		return res;
	}
};