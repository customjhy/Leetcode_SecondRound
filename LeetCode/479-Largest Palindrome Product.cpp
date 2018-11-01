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
	typedef long long ll;

	int mod = 1337;
	ll start, end;

	bool isPrime(ll num){
		for (ll i = end; i * i >= num; i--){
			if (num % i == 0 && num / i <= end){
				//cout << i << endl;
				return true;
			}
		}
		return false;
	}

	ll largestPalindrome(int n) {
		end = (ll)pow(10, n) - 1;
		start = end / 10 + 1;
		for (ll index = end; index >= start; index--){
			ll temp = index;
			ll ans = index;
			while (temp > 0){
				ans = ans * 10 + temp % 10;
				temp /= 10;
			}
			if (isPrime(ans))
				return ans % mod;
		}
		return -1;
	}
};
//
//int main(){
//	int n = 2;
//	cout << (new Solution())->largestPalindrome(n) << endl;
//
//	system("Pause");
//	return 0;
//}