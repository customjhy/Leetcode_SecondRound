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
	unordered_map<string, double> m;

	double dp(int A, int B){
		if (A <= 0 && B <= 0)
			return 0.5;
		else if (A <= 0){
			return 1.0;
		}
		else if (B <= 0){
			return 0;
		}
		string str = to_string(A) + "#" + to_string(B);
		if (m.find(str) != m.end())
			return m[str];
		double res = (dp(A - 4, B) + dp(A - 3, B - 1) + dp(A - 2, B - 2) + dp(A - 1, B - 3)) * 1.0 / 4;
		m[str] = res;
		return res;
	}

	double soupServings(int N) {
		if (N >= 4801)
			return 1;
		N = (N + 24) / 25;
		return dp(N, N);
	}
};