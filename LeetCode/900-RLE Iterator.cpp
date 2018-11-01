#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>

using namespace std;

class RLEIterator {
public:
	typedef pair<int, int> ii;
	deque<ii> de;

	RLEIterator(vector<int> A) {
		for (int i = 0; i < A.size(); i += 2){
			de.push_back({ A[i + 1], A[i] });
		}
	}

	int next(int n) {
		while (n > 0 && !de.empty()){
			int key = de.front().first;
			int times = de.front().second;
			de.pop_front();
			if (times == n)
				return key;
			else if (times < n){
				n -= times;
			}
			else{
				times -= n;
				de.push_front({ key, times });
				return key;
			}
		}
		return -1;
	}
};

/**
* Your RLEIterator object will be instantiated and called as such:
* RLEIterator obj = new RLEIterator(A);
* int param_1 = obj.next(n);
*/