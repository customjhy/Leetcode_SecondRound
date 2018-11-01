#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<functional>

using namespace std;

class MedianFinder {
public:
	priority_queue<int, vector<int>, less<int> > first;
	priority_queue<int, vector<int>, greater<int> > second;

	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		first.push(num);
		while (first.size() >= second.size() + 2){
			int temp = first.top();
			first.pop();
			second.push(temp);
		}
		if (!first.empty() && !second.empty() && first.top() > second.top()){
			int a = first.top();
			first.pop();
			int b = second.top();
			second.pop();
			first.push(b);
			second.push(a);
		}
	}

	double findMedian() {
		if (first.size() == second.size()){
			return (first.top() + second.top()) / 2.0;
		}
		return first.top() * 1.0;
	}
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/