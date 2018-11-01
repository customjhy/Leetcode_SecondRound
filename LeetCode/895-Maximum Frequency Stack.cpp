#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
#include<functional>
#include<unordered_map>
#include<algorithm>

using namespace std;

class FreqStack {
public:
	vector<vector<int> > vec;
	unordered_map<int, int> m;
	int size;

	FreqStack() {
		vec = vector<vector<int> >(10001, vector<int>(0));
		size = 0;
	}

	void push(int x) {
		if (m.find(x) == m.end() || m[x] == 0){
			m[x] = 1;
			size = max(size, 1);
			vec[1].push_back(x);
		}
		else{
			int index = m[x];
			vec[index + 1].push_back(x);
			m[x] = index + 1;
			size = max(size, index + 1);
		}
	}

	int pop() {
		int res = vec[size][vec[size].size() - 1];
		vec[size].pop_back();
		m[res] = size - 1;
		if (vec[size].empty()){
			size--;
		}
		return res;
	}
};

/**
* Your FreqStack object will be instantiated and called as such:
* FreqStack obj = new FreqStack();
* obj.push(x);
* int param_2 = obj.pop();
*/