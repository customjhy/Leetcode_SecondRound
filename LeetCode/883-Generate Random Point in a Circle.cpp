#include<vector>
#include<math.h>

using namespace std;

#define PI 3.1415926

class Solution {
public:
	double R;
	double X;
	double Y;

	Solution(double radius, double x_center, double y_center) {
		R = radius;
		X = x_center;
		Y = y_center;
	}

	vector<double> randPoint() {
		double r = rand() / (double)(RAND_MAX) * sqrt(R);
		double tangle = rand() / (double)(RAND_MAX) * 2 * PI ;
		double x = r * cos(tangle);
		double y = r * sin(tangle);
		return vector<double>{X + x, Y + y};
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(radius, x_center, y_center);
* vector<double> param_1 = obj.randPoint();
*/