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
	int integerBreak(int n) {
		vector<int> vec(n + 1, 1);
		for (int i = 3; i <= n; i++){
			for (int j = 1; j < i; j++){
				vec[i] = max(vec[i], max(j * (i - j), j * vec[i - j]));
				
			}
		}
		return vec[n];
	}
};
//
//int main(){
//	int n = 58;
//	cout << (new Solution())->integerBreak(n);
//
//	system("Pause");
//	return 0;
//}