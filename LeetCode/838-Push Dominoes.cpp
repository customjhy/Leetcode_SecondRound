#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>

using namespace std;

class Solution {
public:
	string pushDominoes(string dominoes) {
		int n = dominoes.length();
		if (n == 0)
			return dominoes;
		vector<int> right(n, -1);
		if (dominoes[0] == 'R')
			right[0] = 0;
		else if (dominoes[0] == '.')
			right[0] = INT_MAX;
		for (int i = 1; i < n; i++){
			if (dominoes[i] == 'L')
				continue;
			if (dominoes[i] == 'R'){
				right[i] = 0;
			}
			else{
				if (right[i - 1] != -1 && right[i - 1] != INT_MAX)
					right[i] = right[i - 1] + 1;
				else
					right[i] = INT_MAX;
			}
		}
		vector<int> left(n, -1);
		if (dominoes[n - 1] == 'L')
			left[n - 1] = 0;
		else if (dominoes[n - 1] == '.')
			left[n - 1] = INT_MAX;
		for (int i = n - 2; i >= 0; i--){
			if (dominoes[i] == 'R')
				continue;
			if (dominoes[i] == 'L')
				left[i] = 0;
			else{
				if (left[i + 1] != -1 && left[i + 1] != INT_MAX){
					left[i] = left[i + 1] + 1;
				}
				else{
					left[i] = INT_MAX;
				}
			}
		}
		for (int i = 0; i < n; i++){
			if (dominoes[i] == '.'){
				if (left[i] < right[i])
					dominoes[i] = 'L';
				else if (left[i] > right[i])
					dominoes[i] = 'R';
			}
		}
		return dominoes;
	}
};