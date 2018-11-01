#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

typedef long long ll;

class Solution {
public:
	int bit(ll a){
		int res = 0;
		while (a > 0){
			res++;
			a /= 10;
		}
		return res;
	}

	bool help(ll a, ll b){
		int count[10] = { 0 };
		while (a > 0){
			count[a % 10]++;
			count[b % 10]--;
			a /= 10;
			b /= 10;
		}
		for (int i = 0; i < 10; i++){
			if (count[i] != 0)
				return false;
		}
		return true;
	}

	bool reorderedPowerOf2(int N) {
		long long num = 1;
		vector<ll> vec;
		while (num < INT_MAX * 10){
			vec.push_back(num);
			num *= 2;
		}
		int b = bit(N);
		for (int i = 0; i < vec.size(); i++){
			if (bit(vec[i]) == b && help(vec[i], N)){
				return true;
			}
		}
		return false;
	}
};