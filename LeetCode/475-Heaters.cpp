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
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (houses.size() == 0)
			return 0;
		if (heaters.size() == 0)
			return -1;
		int pre = 0;
		int index = 0;
		int res = 0;
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		while (index < houses.size()){
			if (houses[index] <= heaters[pre]){
				res = max(res, heaters[pre] - houses[index]);
				index++;
			}
			else{
				break;
			}
		}
		int post = 1;
		for (; index < houses.size(); index++){
			while (post < heaters.size() && heaters[post] <= houses[index]){
				post++;
				pre++;
			}
			if (post >= heaters.size())
				break;
			res = max(res, min(houses[index] - heaters[pre], heaters[post] - houses[index]));
		}
		for (; index < houses.size(); index++){
			res = max(res, houses[index] - heaters[pre]);
		}
		return res;
	}
};