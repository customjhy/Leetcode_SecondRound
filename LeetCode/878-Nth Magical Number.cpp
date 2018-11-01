#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
#include<functional>

using namespace std;

class Solution {
public:
	typedef long long ll;

	//C : lmd
	ll order(ll num, const ll& A, const ll& B, const ll& C){
		if (A % B == 0){
			return num / B;
		}
		else if (B % A == 0){
			return num / A;
		}
		return num / A + num / B - num / C;
	}

	ll gcd(ll a, ll b){
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	ll lmd(ll a, ll b){
		return a * b / gcd(a, b);
	}

	int nthMagicalNumber(int N, int A, int B) {
		const int mod = pow(10, 9) + 7;
		ll left = 2;
		ll right = (ll)pow(10, 13) * 4;
		ll a = (ll)A;
		ll b = (ll)B;
		
		ll c = lmd(a, b);
		while (left < right){
			ll mid = (left + right) / 2;
			//cout << left << "\t" << mid << "\t" << right << endl;
			if (order(mid, a, b, c) < N){
				left = mid + 1;
			}
			else{
				right = mid;
			}
		}
		return (int)(left % mod);
	}
};

//int main(){
//	int N = 1000000000;
//	int A = 40000;
//	int B = 40000;
//	cout << (new Solution())->nthMagicalNumber(N, A, B) << endl;
//
//	system("Pause");
//	return 0;
//}

//res:999720007
//1000000000
//40000
//40000

//res:40
//8
//10
//5

//res:50
//10
//10
//8

//res:10
//int N = 5;
//int A = 2;
//int B = 4;