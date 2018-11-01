#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		if (tree.empty())
			return 0;
		int res = 1;
		unordered_map<int, int> m;
		int left = 0;
		int right = -1;
		//m[tree[0]]++;
		int n = tree.size();
		while (right < n - 1){
			m[tree[++right]]++;
			while (m.size() > 2){
				m[tree[left]]--;
				if (m[tree[left]] == 0){
					m.erase(tree[left]);
				}
				left++;
			}
			res = max(res, right - left + 1);
		}
		return res;
	}
};