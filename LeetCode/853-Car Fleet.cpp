#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		if (position.size() == 0)
			return 0;
		int res = 0;
		map<int, int> m;
		for (int i = 0; i < position.size(); i++){
			m[position[i]] = speed[i];
		}
		double time = -1;
		for (map<int, int> ::reverse_iterator iter = m.rbegin(); iter != m.rend(); iter++){
			if (time < 0){
				time = (target - iter->first) * 1.0 / iter->second;
			}
			else{
				if (time >= (target - iter->first) * 1.0 / iter->second){
					continue;
				}
				else{
					time = (target - iter->first) * 1.0 / iter->second;
					res++;
				}
			}
		}
		return res + 1;
	}
};