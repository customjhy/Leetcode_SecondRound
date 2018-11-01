#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
	int row, col;
	int total;
	unordered_map<int, int> m;

	Solution(int n_rows, int n_cols) {
		row = n_rows;
		col = n_cols;
		total = row * col;
	}

	vector<int> flip() {
		int k = rand() % total--;
		int val = k;
		if (m.find(k) != m.end()){
			val = m[k];
		}
		if (m.find(total) != m.end()){
			m[k] = m[total];
		}
		else{
			m[k] = total;
		}
		return vector<int>{val / col, val % col};
	}

	void reset() {
		total = row * col;
		m.clear();
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(n_rows, n_cols);
* vector<int> param_1 = obj.flip();
* obj.reset();
*/