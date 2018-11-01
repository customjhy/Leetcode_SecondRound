#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	static bool cmp(int a, int b){
		string strA = to_string(a);
		string strB = to_string(b);
		return strA + strB > strB + strA;
	}

	string largestNumber(vector<int>& nums) {
		if (nums.size() == 0)
			return "";
		sort(nums.begin(), nums.end(), cmp);
		string res = "";
		for (int i = 0; i < nums.size(); i++){
			res += to_string(nums[i]);
		}
		return res[0] == '0' ? "0" : res;
	}
};

//int main(){
//	int num[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	vector<int> nums(num, num + 20);
//	Solution* solu = new Solution();
//	cout << solu->largestNumber(nums);
//	system("Pause");
//	return 0;
//}