#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		if (num == 0)return res;
		for (int i = 1; i <= num; i++){
			if (i % 2 == 0){
				res[i] = res[i >> 1];
			}
			else{
				res[i] = res[i >> 1] + 1;
			}
		}
		return res;
	}
};