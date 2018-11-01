#include<string>
#include<cstring>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
	vector<int> uf;
	int cnt;

	int root(int k){
		if (uf[k] != k)
			uf[k] = root(uf[k]);
		return uf[k];
	}

	bool bind(int a, int b){
		int ra = root(a);
		int rb = root(b);
		if (ra == rb){
			return false;
		}
		uf[ra] = rb;
		cnt--;
		return true;
	}

	bool similar(string& str1, string& str2){
		int count = 0;
		for (int i = 0; i < str1.length(); i++){
			if (str1[i] != str2[i])
				count++;
			if (count > 2)
				break;
		}
		if (count == 2){
			return true;
		}
		if (count == 0){
			unordered_set<char> s;
			for (char c : str1){
				if (s.find(c) != s.end())
					return true;
				s.insert(c);
			}
		}
		return false;
	}

	int numSimilarGroups(vector<string>& A) {
		int n = A.size();
		uf = vector<int>(n);
		cnt = n;
		for (int i = 0; i < n; i++){
			uf[i] = i;
		}
		for (int i = 1; i < n; i++){
			for (int j = 0; j < i; j++){
				if (similar(A[i], A[j])){
					bind(i, j);
				}
			}
		}
		return cnt;
	}
};