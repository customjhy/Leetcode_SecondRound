#include<vector>

using namespace std;

class Solution {
public:
	int mirrorReflection(int p, int q) {
		int times = 1;
		while ((q * times) % p != 0){
			times++;
		}
		if (times % 2 == 0)
			return 2;
		int t = q * times / p;
		if (t % 2 == 1)
			return 1;
		return 0;
	}
};