#include<vector>

using namespace std;

class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		vector<int> res(2, 0);
		int sumA = 0;
		int sumB = 0;
		for (int num : A){
			sumA += num;
		}
		for (int num : B){
			sumB += num;
		}
		int sum = (sumA + sumB) / 2;
		int sub = sum - sumA;
		for (int i = 0; i < A.size(); i++){
			int target = A[i] + sub;
			for (int j = 0; j < B.size(); j++){
				if (B[j] == target){
					res[0] = A[i];
					res[1] = B[j];
					return res;
				}
			}
		}
		return res;
	}
};