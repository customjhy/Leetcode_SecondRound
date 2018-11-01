#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	string predictPartyVictory(string senate) {
		int cntR = 0;
		int cntD = 0;
		for (int i = 0; i < senate.length(); i++){
			if (senate[i] == 'R')
				cntR++;
			else
				cntD++;
		}
		int n = senate.length();
		vector<bool> valid(n, true);
		int index = 0;
		while (cntR > 0 && cntD > 0){
			if (senate[index] == 'R'){
				for (int i = 1; i < n; i++){
					if (senate[(index + i) % n] == 'D' && valid[(index + i) % n]){
						valid[(index + i) % n] = false;
						cntD--;
						break;
					}
				}
			}
			else{
				for (int i = 1; i < n; i++){
					if (senate[(index + i) % n] == 'R' && valid[(index + i) % n]){
						valid[(index + i) % n] = false;
						cntR--;
						break;
					}
				}
			}
			while (!valid[(index + 1) % n]){
				index = (index + 1) % n;
			}
			index = (index + 1) % n;
		}
		if (cntD == 0){
			return "Radiant";
		}
		return "Dire";
	}
};