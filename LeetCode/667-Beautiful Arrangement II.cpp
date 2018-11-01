#include<vector>

using namespace std;

class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> res(n);
		int index = 0;
		for (int i = 1; i <= n - k; i++){
			res[index++] = i;
		}
		int flag = 1;
		int pre = n - k;
		for (int i = k; i >= 1; i--){
			res[index] = pre + flag * i;
			flag = -flag;
			pre = res[index++];
		}
		return res;
	}
};