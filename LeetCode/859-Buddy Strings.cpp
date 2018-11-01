#include<string>
#include<cstring>
#include<vector>

using namespace std;

class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.length() != B.length())
			return false;
		vector<int> vec;
		for (int i = 0; i < A.length(); i++){
			if (A[i] != B[i]){
				vec.push_back(i);
				if (vec.size() > 2)
					return false;
			}
		}
		if (vec.size() == 1)
			return false;
		if (vec.size() == 2){
			int a = vec[0];
			int b = vec[1];
			if (A[a] == B[b] && A[b] == B[a])
				return true;
			else
				return false;
		}
		else{
			int count[26] = { 0 };
			for (int i = 0; i < A.length(); i++){
				count[A[i] - 'a']++;
			}
			for (int i = 0; i < 26; i++){
				if (count[i] >= 2)
					return true;
			}
		}
		return false;
	}
};