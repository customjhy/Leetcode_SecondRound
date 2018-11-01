#include<iostream>
#include<string>

using namespace std;

int singleRomanToInt(char c){
	switch (c){
	case 'I':return 1;
	case 'V':return 5;
	case 'X':return 10;
	case 'L':return 50;
	case 'C':return 100;
	case 'D':return 500;
	case 'M':return 1000;
	default:return -1;
	}
}

int romanToInt(string s) {
	int temp = 0;
	int sum = 0;
	int i, j;
	int max;
	int size = s.length();
	while (temp < size){
		max = temp;
		for (i = temp + 1; i < size; i++){
			if (singleRomanToInt(s[i])>singleRomanToInt(s[max]))
				max = i;
		}
		for (j = temp; j < max; j++){
			sum = sum - singleRomanToInt(s[j]);
		}
		sum += singleRomanToInt(s[max]);
		temp = max + 1;
	}
	return sum;
}
//
//int main(){
//	string temp;
//	cin >> temp;
//	cout << romanToInt(temp) << endl;
//
//	system("pause");
//	return 0;
//}