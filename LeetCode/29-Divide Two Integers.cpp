#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int divide(long long dividend, long long divisor) {
		int minus = 1;
		if (dividend < 0 && divisor < 0){
			dividend = -dividend;
			divisor = -divisor;
		}
		else if (dividend < 0){
			minus = -1;
			dividend = -dividend;
		}
		else if (divisor < 0){
			minus = -1;
			divisor = -divisor;
		}
		if (dividend < divisor)
			return 0;
		if (divisor == 1){
			if (minus * dividend < INT_MIN || minus * dividend > INT_MAX)
				return INT_MAX;
			else
				return minus * dividend;
		}
		vector<pair<long long, long long>> vec;
		vec.push_back(make_pair(divisor, 1));
		while (vec[vec.size() - 1].first + vec[vec.size() - 1].first <= dividend){
			vec.push_back(make_pair(vec[vec.size() - 1].first + vec[vec.size() - 1].first, vec[vec.size() - 1].second + vec[vec.size() - 1].second));
		}
		int res = 0;
		for (int i = vec.size() - 1; i >= 0; i--){
			if (dividend >= vec[i].first){
				res += vec[i].second;
				dividend -= vec[i].first;
			}
		}
		if (minus * res < INT_MIN || minus * res > INT_MAX)
			return INT_MAX;
		return minus * res;
	}
};