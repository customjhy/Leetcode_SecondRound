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

class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		unordered_set<int> s(A.begin(), A.end());
		int len = 2;
		int res = 2;
		for (int i = 0; i < A.size() - 2; i++){
			for (int j = i + 1; j < A.size() - 1; j++){
				len = 2;
				int pre = A[i];
				int cur = A[j];
				while (s.find(pre + cur) != s.end()){
					int temp = pre + cur;
					pre = cur;
					cur = temp;
					len++;
				}
				res = max(res, len);
			}
		}
		return res > 2 ? res : 0;
	}
};