#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
#include<functional>

using namespace std;

class Solution {
public:
	const int mod = 1000000007;
	int size;

	int get(vector<int>& sum, int index){
		return sum[size] - sum[size - index] - sum[index];
	}

	int sumSubseqWidths(vector<int>& A) {
		if (A.size() <= 1)return 0;
		size = A.size();
		sort(A.begin(), A.end());
		vector<int> sum(size + 1);
		sum[0] = 0;
		for (int i = 1; i <= size; i++){
			sum[i] = sum[i - 1] + A[i - 1];
		}
		int res = 0;
		for (int i = 1; i <= size - 1; i++){
			res = ((res * 2) % mod + get(sum, i)) % mod;
		}
		return res;
	}
};