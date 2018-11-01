#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
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
	vector<int> get(vector<int>& nums, int len){
		if (len == 0)
			return vector<int>();
		vector<int> res = vector<int>(len, -1);
		int index = 0;
		res[index] = nums[0];
		for (int i = 1; i < nums.size(); i++){
			while (index >= 0 && nums[i] > res[index] && nums.size() - i > len - index - 1){
				index--;
			}
			//cout << index << "\t" << i << "\t" << nums[i] << endl;
			if (index < (int)res.size() - 1)
				res[++index] = nums[i];
			/*for (int k = 0; k < len; k++){
				cout << res[k] << "\t";
			}
			cout << endl;*/
		}
		return res;
	}
	
	bool cmp(vector<int>& nums1, int i, vector<int>& nums2, int j){
		while (i < nums1.size() && j < nums2.size()){
			if (nums1[i] > nums2[j])
				return true;
			else if (nums1[i] < nums2[j])
				return false;
			i++;
			j++;
		}
		if (i == nums1.size())
			return false;
		return true;
	}

	vector<int> merge(vector<int>& nums1, vector<int>& nums2){
		vector<int> res;
		int i = 0;
		int j = 0;
		while (i < nums1.size() && j < nums2.size()){
			if (cmp(nums1, i, nums2, j)){
				res.push_back(nums1[i++]);
			}
			else{
				res.push_back(nums2[j++]);
			}
		}
		while (i < nums1.size()){
			res.push_back(nums1[i++]);
		}
		while (j < nums2.size()){
			res.push_back(nums2[j++]);
		}
		/*if (res.empty())
			cout << "false";
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << "  ";
		cout << endl;*/
		return res;
	}

	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> res;
		for (int i = min((int)nums1.size(), k), j = k - i; i >= 0 && j <= nums2.size(); i--, j = k - i){
			vector<int> temp1 = get(nums1, i);
			vector<int> temp2 = get(nums2, j);
			vector<int> temp = merge(temp1, temp2);
			//cout << temp.size() << "\t" << res.size() << endl;
			if (cmp(temp, 0, res, 0)){
				res = temp;
				//cout << "yes" << endl;
			}
		}
		return res;
	}
};
//
//int main(){
//	vector<int> nums1{ 2, 5, 6, 4, 4, 0 };
//	vector<int> nums2{ 7, 3, 8, 0, 6, 5, 7, 6, 2 };
//	int k = 15;
//	/*vector<int> nums1{ 9, 1, 2, 5, 8, 3 };
//	vector<int> nums2{ 3, 4, 6, 5 };
//	int k = 5;*/
//	/*vector<int> nums1{ 6, 7 };
//	vector<int> nums2{ 6, 0, 4 };
//	int k = 5;*/
//	/*vector<int> nums1{ 3, 4, 6, 5 };
//	vector<int> nums2{ 9, 1, 2, 5, 8, 3 };
//	int k = 5;*/
//	/*vector<int> res = (new Solution())->get(nums1, 2);
//	for (int i = 0; i < res.size(); i++){
//		cout << res[i] << "\t";
//	}*/
//	vector<int> res = (new Solution())->maxNumber(nums1, nums2, k);
//	for (int i = 0; i < res.size(); i++){
//		cout << res[i] << "\t";
//	}
//	system("Pause");
//	return 0;
//}


