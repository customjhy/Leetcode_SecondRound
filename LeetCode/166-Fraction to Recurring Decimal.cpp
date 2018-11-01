#include<iostream>
#include<cstring>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long a = (long long)numerator;
		long long b = (long long)denominator;
		int minus = a * b < 0 ? -1 : 1;
		a = abs(a);
		b = abs(b);
		long long pre = a / b;
		long long remain = a % b;
		string temp;
		unordered_map<long long, unordered_map<long long, long long>> m;
		long long real;
		while (remain != 0){
			real = remain * 10 / b;
			remain = remain * 10 % b;
			if (m.count(real) == 1 && m[real].count(remain) == 1){
				int index = m[real][remain];
				if (minus == 1)
					return to_string(pre) + "." + temp.substr(0, index) + "(" + temp.substr(index) + ")";
				else
					return "-" + to_string(pre) + "." + temp.substr(0, index) + "(" + temp.substr(index) + ")";
			}
			m[real][remain] = temp.size();
			temp += to_string(real);
		}
		if (temp.empty())
			return to_string(minus * pre);
		if (minus == 1)
			return to_string(pre) + "." + temp;
		else
			return "-" + to_string(pre) + "." + temp;
	}
};