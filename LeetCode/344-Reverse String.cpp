#include<iostream>
#include<string>
#include<algorithm> 

using namespace std;

string reverseString(string s) {
	char temp;
	for (int i = 0; i < s.length() / 2; i++){
		temp = s[i];
		s[i] = s[s.length() - 1 - i];
		s[s.length() - 1 - i] = temp;
	}
	return s;
}
//
//int main(){
//	string str("a");
//	string temp;
//	temp = reverseString(str);
//	cout << temp << endl;
//
//	system("pause");
//	return 0;
//}