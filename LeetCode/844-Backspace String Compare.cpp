#include<stack>
#include<string>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> s;
		stack<char> t;
		for (unsigned int i = 0; i < S.length(); i++){
			if (S[i] != '#'){
				s.push(S[i]);
			}
			else if(!s.empty()){
				s.pop();
			}
		}
		for (unsigned int i = 0; i < T.length(); i++){
			if (T[i] != '#'){
				t.push(T[i]);
			}
			else if (!t.empty()){
				t.pop();
			}
		}
		while (!s.empty() && !t.empty()){
			if (s.top() == t.top()){
				s.pop();
				t.pop();
			}
			else{
				return false;
			}
		}
		if (s.empty() && t.empty()){
			return true;
		}
		return false;
	}
};