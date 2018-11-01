#include<string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string res = "";
		int gap = 2 * numRows - 2;
		int len = s.length();
		for (int i = 0; i < len; i += gap){
			res += s[i];
		}
		int left = 1;
		int right = gap - 1;
		while (left < right){
			for (int i = left,j = right;; i += gap, j += gap){
				if (i < len){
					res += s[i];
				}
				else{
					break;
				}
				if (j < len){
					res += s[j];
				}
				else{
					break;
				}
			}
			left++;
			right--;
		}
		for (; left < len; left += gap){
			res += s[left];
		}
		return res;
	}
};