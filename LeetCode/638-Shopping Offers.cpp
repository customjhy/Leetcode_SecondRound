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
	unordered_map<string, int> M;

	string encode(vector<int>& needs){
		string res = "";
		for (int i = 0; i < needs.size(); i++){
			res += needs[i] + "#";
		}
		return res;
	}

	int help(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int start){
		string str = encode(needs);
		if (M.find(str) != M.end())
			return M[str];
		int res = 0;
		for (int i = 0; i < price.size(); i++){
			res += price[i] * needs[i];
		}
		for (int i = start; i < special.size(); i++){
			bool flag = true;
			for (int k = 0; flag; k++){
				for (int j = 0; j < needs.size(); j++){
					if (special[i][j] * k> needs[j]){
						flag = false;
						break;
					}
				}
				if (flag){
					for (int j = 0; j < needs.size(); j++){
						needs[j] -= k * special[i][j];
					}
					res = min(res, k * special[i][special[i].size() - 1] + help(price, special, needs, i + 1));
					for (int j = 0; j < needs.size(); j++){
						needs[j] += k * special[i][j];
					}
				}
			}
		}
		M[str] = res;
		return res;
	}

	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		return help(price, special, needs, 0);
	}
};