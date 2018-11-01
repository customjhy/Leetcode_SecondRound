#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<string>
#include<cstring>
#include<string.h>
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
	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		int res = 0;
		int temp = n2;
		int i = 0, j = 0;
		while (n1 > 0){
			if (s1[i] == s2[j]){
				i++;
				j++;
			}
			else{
				i++;
			}
			if (i == s1.length()){
				i = 0;
				n1--;
			}
			if (j == s2.length()){
				j = 0;
				n2--;
				if (n2 == 0){
					n2 = temp;
					res++;
				}
			}
		}
		return res;
	}
};