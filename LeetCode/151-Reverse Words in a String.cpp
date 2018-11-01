#include<cstring>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	void swap(string& s, int start, int end){
		char c = ' ';
		while (start < end){
			c = s[start];
			s[start] = s[end];
			s[end] = c;
			start++;
			end--;
		}
	}

	void reverseWords(string &s) {
		if (s.empty())
			return;
		string str;
		int i = 0;
		for (i = 0; i < s.length(); i++){
			if (s[i] != ' ')
				break;
		}
		for (; i < s.length(); i++){
			if (!str.empty() && str[str.length() - 1] == ' ' && s[i] == ' ')
				continue;
			str = str + s[i];
		}
		if (str.empty())
			return;
		if (str[str.length() - 1] == ' ')
			s = str.substr(0, str.length() - 1);
		else
			s = str;
		if (s.empty())
			return;
		swap(s, 0, s.length() - 1);
		int left = 0;
		int right = 0;
		while (left < s.length() && s[left] == ' '){
			left++;
			right++;
		}
		while (right < s.length()){
			if (s[right] != ' ')
				right++;
			else{
				swap(s, left, right - 1);
				left = right + 1;
				right++;
			}
		}
		if (s[right - 1] != ' '){
			swap(s, left, right - 1);
		}
	}
};

//int main(){
//	Solution *solu = new Solution();
//	string str = "the sky is blue";
//	solu->reverseWords(str);
//	cout << str;
//	system("pause");
//	return 0;
//}