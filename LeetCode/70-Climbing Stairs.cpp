#include<iostream>
#include<math.h>

using namespace std;

int climbNumber(int two, int one){
	int sum = two + one;
	double result = 1;
	for (int i = one + 1, j = two; i <= sum&&j >= 1; i++, j--){
		result = result * i;
		result = result / j;
	}
	return (int)(result + 0.5);
}

int climbStairs(int n) {
	if (n == 0)return 0;
	int two, one;
	int result = 0;
	for (two = 0; 2 * two <= n; two++){
		one = n - 2 * two;
		result += climbNumber(two, one);
	}
	return result;
}
