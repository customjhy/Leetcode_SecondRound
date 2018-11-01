#include<iostream>
#include<cstdio>
#include<stdio.h>
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
	int findIntegers(int num) {
		if (num <= 2)return num + 1;
		if (num == 3)return 3;
		string str = "";
		int temp = num;
		while (temp > 0){
			if (temp % 2)
				str += "1";
			else
				str += "0";
			temp /= 2;
		}
		//reverse(str.begin(), str.end());
		int n = str.length();
		vector<int> dp0(n, 1);
		vector<int> dp1(n, 1);
		for (int i = 1; i < n; i++){
			dp0[i] = dp1[i - 1] + dp0[i - 1];
			dp1[i] = dp0[i - 1];
		}
		int res = dp0[n - 1] + dp1[n - 1];
		for (int i = n - 2; i >= 0; i--){
			if (str[i] == '1' && str[i + 1] == '1')break;
			if (str[i] == '0' && str[i + 1] == '0')res -= dp1[i];
		}
		return res;
	}
};