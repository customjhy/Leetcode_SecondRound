#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool cmp(const Interval& a, const Interval& b){
		if (a.start == b.start)
			return a.end < b.end;
		return a.start < b.start;
	}

	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if (intervals.empty())
			return res;
		sort(intervals.begin(), intervals.end(), cmp);
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++){
			Interval temp = intervals[i];
			if (temp.start <= res[res.size() - 1].end){
				res[res.size() - 1].end = max(res[res.size() - 1].end, temp.end);
			}
			else{
				res.push_back(temp);
			}
		}
		return res;
	}
};