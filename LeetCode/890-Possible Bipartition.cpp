#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b){
		if (a[0] == b[0])
			return a[1] < b[1];
		return a[0] < b[0];
	}

	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		sort(dislikes.begin(), dislikes.end(), cmp);
		unordered_set<int> a;
		unordered_set<int> b;
		for (vector<int> vec : dislikes){
			if (a.find(vec[0]) != a.end()){
				if (a.find(vec[1]) != a.end())
					return false;
				b.insert(vec[1]);
			}
			else if (b.find(vec[0]) != b.end()){
				if (b.find(vec[1]) != b.end())
					return false;
				a.insert(vec[1]);
			}
			else{
				if (a.find(vec[1]) != a.end()){
					b.insert(vec[0]);
				}
				else if (b.find(vec[1]) != b.end()){
					a.insert(vec[0]);
				}
				else{
					a.clear();
					b.clear();
					a.insert(vec[0]);
					b.insert(vec[1]);
				}
			}
		}
		return true;
	}
};