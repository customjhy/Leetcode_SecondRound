#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<functional>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int gcd(int a, int b){
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	int maxPoints(vector<Point>& points) {
		if (points.size() < 2)
			return points.size();
		int res = 0;
		for (int i = 0; i < points.size(); i++){
			map<pair<int, int>, int> m;
			int overlap = 1;
			int vertical = 0;
			int curMax = 0;
			for (int j = i + 1; j < points.size(); j++){
				if (points[j].x == points[i].x && points[j].y == points[i].y)
					overlap++;
				else if (points[i].x == points[j].x)
					vertical++;
				else{
					int x = points[j].x - points[i].x;
					int y = points[j].y - points[i].y;
					int t = gcd(x, y);
					x /= t;
					y /= t;
					m[make_pair(x, y)]++;
					curMax = max(curMax, m[make_pair(x, y)]);
				}
			}
			curMax = max(curMax, vertical) + overlap;
			res = max(res, curMax);
		}
		return res;
	}
};