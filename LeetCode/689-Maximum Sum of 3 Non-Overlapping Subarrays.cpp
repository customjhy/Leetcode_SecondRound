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
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int size = nums.size();
		vector<int> sum(size + 1, 0);
		for (int i = 1; i <= size; i++){
			sum[i] = sum[i - 1] + nums[i - 1];
		}
		vector<int> left(size, 0);
		for (int i = k; i < size; i++){
			if (sum[i + 1] - sum[i + 1 - k] > sum[left[i - 1] + k] - sum[left[i - 1]]){
				left[i] = i + 1 - k;
			}
			else{
				left[i] = left[i - 1];
			}
		}
		for (int i = 0; i < size; i++){
			cout << left[i] << "\t";
		}
		cout << endl;
		for (int i = 1; i <= size; i++){
			cout << sum[i] << "\t";
		}
		cout << endl;
		vector<int> right(size, size - k);
		for (int i = size - k - 1; i >= 0; i--){
			if (i == 6){
				int j = sum[i + k] - sum[i];
				int t = sum[right[i + 1] + k] - sum[right[i + 1]];
				cout << "i == 6" << j << "\t" << t << endl;
			}
			if (sum[i + k] - sum[i] >= sum[right[i + 1] + k] - sum[right[i + 1]]){
				right[i] = i;
			}
			else{
				right[i] = right[i + 1];
			}
		}
		for (int i = 0; i < size; i++){
			cout << right[i] << "\t";
		}
		cout << endl;
		vector<int> res;
		int add = 0;
		for (int i = k; i <= size - 2 * k; i++){
			if (sum[i + k] - sum[i] + sum[left[i - 1] + k] - sum[left[i - 1]] + sum[right[i + k] + k] - sum[right[i + k]] > add){
				res = vector<int>{left[i - 1], i, right[i + k]};
				add = sum[i + k] - sum[i] + sum[left[i - 1] + k] - sum[left[i - 1]] + sum[right[i + k] + k] - sum[right[i + k]];
			}
		}
		return res;
	}
};

class Solution2 {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int n = nums.size(), maxsum = 0;
		vector<int> sum = { 0 }, posLeft(n, 0), posRight(n, n - k), ans(3, 0);
		for (int i : nums) sum.push_back(sum.back() + i);
		// DP for starting index of the left max sum interval
		for (int i = k, tot = sum[k] - sum[0]; i < n; i++) {
			if (sum[i + 1] - sum[i + 1 - k] > tot) {
				posLeft[i] = i + 1 - k;
				tot = sum[i + 1] - sum[i + 1 - k];
			}
			else
				posLeft[i] = posLeft[i - 1];
		}
		for (int i = 0; i < n; i++){
			cout << posLeft[i] << "\t";
		}
		cout << endl;
		// DP for starting index of the right max sum interval
		// caution: the condition is ">= tot" for right interval, and "> tot" for left interval
		for (int i = n - k - 1, tot = sum[n] - sum[n - k]; i >= 0; i--) {
			if (sum[i + k] - sum[i] >= tot) {
				posRight[i] = i;
				tot = sum[i + k] - sum[i];
			}
			else
				posRight[i] = posRight[i + 1];
		}
		for (int i = 0; i < n; i++){
			cout << posRight[i] << "\t";
		}
		cout << endl;
		// test all possible middle interval
		for (int i = k; i <= n - 2 * k; i++) {
			int l = posLeft[i - 1], r = posRight[i + k];
			int tot = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
			if (tot > maxsum) {
				maxsum = tot;
				ans = { l, i, r };
			}
		}
		return ans;
	}
};

//
//int main(){
//	//res : [1,4,7]
//	vector<int> nums{ 7, 13, 20, 19, 19, 2, 10, 1, 1, 19 };
//	int k = 3;
//	vector<int> res = (new Solution)->maxSumOfThreeSubarrays(nums, k);
//	(new Solution2)->maxSumOfThreeSubarrays(nums, k);
//	for (int i = 0; i < 3; i++){
//		cout << res[i] << "\t";
//	}
//
//	system("Pause");
//	return 0;
//}
//

