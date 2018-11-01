#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	typedef long long ll;

	int minPatches(vector<int>& nums, int n) {
		int res = 0;
		ll sum = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() && sum < n; i++){
			if (sum + 1 < nums[i]){
				res++;
				sum = 2 * sum + 1;
				i--;
			}
			else{
				sum += nums[i];
			}
		}
		while (sum < n){
			sum = 2 * sum + 1;
			res++;
		}
		return res;
	}
};


//int main(){
//	//res : 28
//	vector<int> nums{ 1, 2, 31, 33 };
//	int n = 2147483647;
//	cout << (new Solution())->minPatches(nums, n);
//
//	system("Pause");
//	return 0;
//}