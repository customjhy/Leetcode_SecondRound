#include<cstring>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		for (int i = 0; i < str.size();){//trim
			if (str[i] == ' ')
				i++;
			else{
				str = str.substr(i);
				break;
			}
		}
		if (str.empty() || (str[0] != '-' && !(str[0] >= '0' && str[0] <= '9') && str[0] != '+'))
			return 0;
		int minus = 1;
		if (str[0] == '-'){
			minus = -1;
			str = str.substr(1);
		}
		else if (str[0] == '+')
			str = str.substr(1);
		long long res = 0;
		for (unsigned int i = 0; i < str.length(); i++){
			if (str[i] >= '0' && str[i] <= '9'){
				res = res * 10 + str[i] - '0';
				if (minus == 1 && res > INT_MAX){
					return INT_MAX;
				}
				else if (minus == -1 && res * -1 < INT_MIN){
					return INT_MIN;
				}
			}
			else
				return minus * (int)res;
		}
		string temp;
		temp.append('c' + "");

		return minus * (int)res;
	}
};
//
//int main(){
//	Solution *solu = new Solution();
//	string str = "   +-42";
//	cout << solu->myAtoi(str);
//	system("pause");
//	return 0;
//}