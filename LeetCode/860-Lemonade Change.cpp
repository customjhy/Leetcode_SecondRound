#include<vector>

using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int five = 0;
		int ten = 0;
		for (int bill : bills){
			if (bill == 5){
				five++;
			}
			else if (bill == 10){
				if (five == 0)
					return false;
				five--;
				ten++;
			}
			else{
				if (ten > 0){
					if (five == 0)
						return false;
					five--;
					ten--;
				}
				else{
					if (five < 3)
						return false;
					five -= 3;
				}
			}
		}
		return true;
	}
};