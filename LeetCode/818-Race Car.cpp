#include<iostream>
#include<cstdio>
#include<string>
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
	int racecar(int target) {
		vector<int> dp(target + 1, INT_MAX);
		dp[0] = 0;
		int gap = 1;
		int step = 1;
		for (int i = 1; i <= target; i += gap){
			dp[i] = step;
			gap *= 2;
			step++;
		}
		/*for (int i = 1; i <= target; i++){
			cout << i << "\t" <<dp[i]<< endl;
		}*/
		for (int i = 2; i <= target; i++){
			int j;
			for (j = 1; j < 31; j++){
				if ((1 << j) - 1 >= i)
					break;
			}
			int add = (1 << j) - 1;
			if (add == i)
				continue;
			dp[i] = min(dp[add - i] + j + 1, dp[i]);
			for (int m = 0; m < j - 1; m++){
				dp[i] = min(dp[i], dp[i - (add + 1) / 2 + (1 << m)] + j + m + 1);
			}
		}
		/*cout << endl;
		for (int i = 1; i <= target; i++){
			cout << i << "\t" <<dp[i]<< endl;
		}*/
		return dp[target];
	}
};

//
//int main(){
//	int target = 5;
//	cout << (new Solution())->racecar(target) << endl;
//
//
//	system("pause");
//	return 0;
//}