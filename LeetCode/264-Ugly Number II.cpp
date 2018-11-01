#include<iostream>
#include<cstdio>
#include<string>
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
	typedef long long ll;

	int nthUglyNumber(int n) {
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		pq.push(1);
		ll cur = 0;
		ll pre = 0;
		while (n-- > 0){
			cur = pq.top();
			pq.pop();
			while (cur == pre){
				cur = pq.top();
				pq.pop();
			}
			pre = cur;
			pq.push(cur * 2);
			pq.push(cur * 3);
			pq.push(cur * 5);
		}
		return (int)cur;
	}
};


//int main(){
//	(new Solution())->nthUglyNumber(1);
//
//	system("Pause");
//	return 0;
//}