#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<vector<int>> knap(coins.size() + 1, vector<int>(amount + 1, 0));
		knap[0][0] = 1;
		for (int i = 1; i <= coins.size(); i++){
			knap[i][0] = 1;
			for (int j = 1; j <= amount; j++){
				knap[i][j] = knap[i - 1][j] + (j >= coins[i - 1] ? knap[i][j - coins[i - 1]] : 0);
			}
		}
		return knap[coins.size()][amount];
	}
};