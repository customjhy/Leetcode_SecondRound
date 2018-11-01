#include<stack>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

class Solution {
public:
	char help(stack<char>& chStack, stack<ll>& inStack, int K){
		if (inStack.top() == K){
			while (!chStack.empty()){
				if (chStack.top() >= 'a' && chStack.top() <= 'z'){
					return chStack.top();
				}
				chStack.pop();
			}
		}
		char c = chStack.top();
		chStack.pop();
		ll n = inStack.top();
		inStack.pop();
		K = K % inStack.top();
		if (K == 0)
			K = inStack.top();
		return help(chStack, inStack, K);
	}

	string decodeAtIndex(string S, int K) {
		stack<char> chStack;
		stack<ll> inStack;
		chStack.push(S[0]);
		inStack.push(1);
		int index = 1;
		while (inStack.top() < K && index < S.length()){
			chStack.push(S[index]);
			if (S[index] >= '0' && S[index] <= '9'){
				inStack.push(inStack.top() * (S[index] - '0'));
			}
			else{
				inStack.push(inStack.top() + 1);
			}
			index++;
		}
		string res;
		res.resize(2);
		res[0] = help(chStack, inStack, K); 
			return res;
	}
};