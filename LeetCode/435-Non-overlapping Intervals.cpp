#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<functional>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool cmp(Interval& i1, Interval& i2){
		if (i1.start == i2.start)
			return i1.end < i2.end;
		return i1.start < i2.start;
	}

	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.empty())
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		Interval pre = intervals[0];
		int cnt = 1;
		for (int i = 1; i < intervals.size(); i++){
			Interval cur = intervals[i];
			if (cur.start == pre.start)
				continue;
			if (cur.start >= pre.end){
				pre = cur;
				cnt++;
			}
			else if (cur.end <= pre.end){
				pre = cur;
			}
			else{
				continue;
			}
		}
		return intervals.size() - cnt;
	}
};