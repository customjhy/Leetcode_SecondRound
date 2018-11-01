#include<cmath>
#include<vector>
#include<unordered_set>
#include<ctime>

using namespace std;

class Solution {
public:
	int n;
	unordered_set<int> s;
	bool flag;
	vector<int> vec;

	Solution(int N, vector<int> blacklist) {
		srand(time(NULL));
		n = N;
		s.insert(blacklist.begin(), blacklist.end());
		flag = false;
		if (N < 100000 && N / 2 < blacklist.size()){
			for (int i = 0; i < N; i++){
				if (s.find(i) == s.end()){
					vec.push_back(i);
				}
			}
			flag = true;
		}
	}

	int help(int left, int right){
		if (left > right)
			return -1;
		if (left == right){
			if (s.find(left) != s.end())
				return -1;
			return left;
		}
		int mid = (left + right) >> 1;
		int res = 0;
		if (rand() % 2 == 0){
			res = help(left, mid);
			if (res == -1){
				return help(mid + 1, right);
			}
			else{
				return res;
			}
		}
		else{
			res = help(mid + 1, right);
			if (res == -1){
				return help(left, mid);
			}
			else{
				return res;
			}
		}
		return -1;
	}

	int pick() {
		if (flag){
			return vec[rand() % vec.size()];
		}
		return help(0, n - 1);
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(N, blacklist);
* int param_1 = obj.pick();
*/