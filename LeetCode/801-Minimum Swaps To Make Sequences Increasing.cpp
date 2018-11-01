#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	int minSwap(vector<int>& A, vector<int>& B) {
		int size = A.size();
		vector<int> swap(size, 0);//i位置交换
		vector<int> fix(size, 0);//i位置不交换
		swap[0] = 1;
		for (int i = 1; i < size; i++){
			if (A[i - 1] >= B[i] || B[i - 1] >= A[i]){
				fix[i] = fix[i - 1];
				swap[i] = swap[i - 1] + 1;
			}
			else if (A[i - 1] >= A[i] || B[i - 1] >= B[i]){
				swap[i] = fix[i - 1] + 1;
				fix[i] = swap[i - 1];
			}
			else{
				int minn = min(swap[i - 1], fix[i - 1]);
				swap[i] = minn + 1;
				fix[i] = minn;
			}
		}
		return min(fix[size - 1], swap[size - 1]);
	}
};