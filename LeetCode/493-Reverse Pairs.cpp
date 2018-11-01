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

	int res;

	void merge(vector<ll>& nums, int left, int mid, int right){
		int i = left;
		int j = mid + 1;
		while (i <= mid && j <= right){
			while (j <= right && nums[i] > nums[j] * 2){
				j++;
			}
			//cout<<left<<"\t"<<right<<"\t"<<j - (mid + 1)<<endl;
			res += j - (mid + 1);
			i++;
		}
		while (i <= mid){
			//cout<<"2jieduan"<< left<<"\t"<<right<<"\t"<<j - (mid + 1)<<endl;
			res += j - (mid + 1);
			i++;
		}
		int len = right - left + 1;
		vector<int> vec(len, 0);
		int index = 0;
		i = left;
		j = mid + 1;
		while (i <= mid && j <= right){
			if (nums[i] < nums[j]){
				vec[index++] = nums[i++];
			}
			else{
				vec[index++] = nums[j++];
			}
		}
		while (i <= mid){
			vec[index++] = nums[i++];
		}
		while (j <= right){
			vec[index++] = nums[j++];
		}
		index = 0;
		for (int i = left; i <= right; i++){
			nums[i] = vec[index++];
		}
		return;
	}

	void divide(vector<ll>& nums, int left, int right){
		if (left >= right){
			return;
		}
		int mid = (left + right) >> 1;
		divide(nums, left, mid);
		divide(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}


	int reversePairs(vector<int>& nums) {
		res = 0;
		vector<ll> num(nums.begin(), nums.end());
		divide(num, 0, num.size() - 1);
		return res;
	}
};

//int main(){
//	vector<int> vec{ 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647 };// π”√long long
//	cout << (new Solution())->reversePairs(vec) << endl;
//
//	system("Pause");
//	return 0;
//}