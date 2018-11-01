#include<math.h>

using namespace std;

class Solution {
public:
	bool isPrime(int N){
		for (int i = 3; i <= (int)sqrt(N * 1.0) + 1; i++){
			if (N % i == 0)
				return false;
		}
		return true;
	}

	bool isPalindrome(int N){
		int temp = N;
		int res = 0;
		while (temp > 0){
			res = res * 10 + temp % 10;
			temp /= 10;
		}
		return res == N;
	}

	int primePalindrome(int N) {
		int end = 200000001;
		for (int i = N; i < end; i++){
			if (i % 2 == 1 && isPalindrome(i) && isPrime(i))
				return i;
		}
		return end;
	}
};