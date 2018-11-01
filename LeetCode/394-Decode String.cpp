#include<string>
#include<stack>
#include<iostream>
#include<cstring>

using namespace std;

//class Solution {
//public:
//	string decodeString(string s) {
//		if (s.empty())
//			return "";
//		stack<int> times;
//		stack<string> strs;
//		int left = 0;
//		int right = 0;
//		string res = "";
//		for (int i = 0; i < s.length(); i++){
//			if (s[i] <= '9' && s[i] >= '0'){
//				left = i;
//				right = i;
//				while (right < s.length() && s[right] <= '9' && s[right] >= '0'){
//					right++;
//				}
//				int num = stoi(s.substr(left, right - left));
//				times.push(num);
//				i = right - 1;
//			}
//			else if (s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A'){
//				left = i;
//				right = i;
//				while (right < s.length() && (s[right] <= 'z' && s[right] >= 'a' || s[right] <= 'Z' && s[right] >= 'A')){
//					right++;
//				}
//				string str = s.substr(left, right - left);
//				if (i > 0 && s[i - 1] == '['){
//					strs.push(str);
//				}
//				else{
//					if (times.empty()){
//						res = res + str;
//					}
//					else{
//						string temp = strs.top();
//						strs.pop();
//						strs.push(temp + str);
//					}
//				}
//				i = right - 1;
//			}
//			else if (s[i] == ']'){
//				int time = times.top();
//				string str = strs.top();
//				times.pop();
//				strs.pop();
//				string temp = "";
//				while (time-- > 0){
//					temp = temp + str;
//				}
//				if (times.empty()){
//					res = res + temp;
//				}
//				else{
//					if (strs.empty()){
//						strs.push(temp);
//					}
//					else{
//						string tempStr = strs.top() + temp;
//						strs.pop();
//						strs.push(tempStr);
//					}
//				}
//			}
//		}
//		return res;
//	}
//};
//
//int main(){
//	Solution* solu = new Solution();
//	string str = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
//	//"zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef"
//	cout << solu->decodeString(str);
//	system("pause");
//	return 0;
//}

class Solution {
public:
	string help(string& s, int& i){
		string res = "";
		while (i < s.length() && s[i] != ']'){
			if (!isdigit(s[i]))
				res += s[i];
			else{
				int n = 0;
				while (i < s.length() && isdigit(s[i])){
					n = n * 10 + s[i] - '0';
					i++;
				}
				i++;//[
				string temp = help(s, i);
				i++;
				while (n-- > 0){
					res += temp;
				}
				i++;
			}
		}
		return res;
	}

	string decodeString(string s) {
		int i = 0;
		return help(s, i);
	}
};