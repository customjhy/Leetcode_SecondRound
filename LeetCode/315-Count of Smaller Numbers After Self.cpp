#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<functional>

using namespace std;

class Solution {
public:
	vector<int> BIT;
	int N;//size of BIT

	int lowbit(int x){
		return x & (-x);
	}

	int sum(int i){
		int temp = 0;
		int res = 0;
		while (i >= 1){
			res += BIT[i];
			i -= lowbit(i);
		}
		return res;
	}

	void insert(int i){
		while (i <= N){
			BIT[i]++;
			i += lowbit(i);
			//cout<<i<<"\t"<<N<<endl;
		}
	}

	vector<int> countSmaller(vector<int>& nums) {
		if (nums.size() == 0){
			return nums;
		}
		int size = nums.size();
		vector<int> vec(nums.begin(), nums.end());
		sort(vec.begin(), vec.end());
		unordered_map<int, int> m;
		m[vec[0]] = 1;
		int index = 2;
		for (int i = 1; i < vec.size(); i++){
			if (vec[i] == vec[i - 1])
				continue;
			m[vec[i]] = index++;
		}
		N = m.size();
		BIT = vector<int>(N + 1, 0);
		vec.resize(size, 0);
		for (int i = size - 1; i >= 0; i--){
			vec[i] = sum(m[nums[i]] - 1);
			//vec[i] -= BIT[lowbit(m[nums[i]])];
			//cout<<"sum"<<endl;
			insert(m[nums[i]]);
			//cout<<"insert"<<endl;
		}
		/*for(int i = 1;i <= N;i++){
		cout<<BIT[i]<<"\t";
		}*/
		return vec;
	}
};