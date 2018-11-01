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
	int size;

	int help(vector<string>& D, string str){
		while (!str.empty() && str[0] == '0'){
			return 0;
		}
		if (str.empty())
			return 0;
		int res = 0;
		if (str.length() == 1){
			for (int i = 0; i < D.size(); i++){
				if (D[i][0] <= str[0]){
					res++;
				}
				else{
					break;
				}
			}
			return res;
		}
		for (int i = 0; i < size; i++){
			if (D[i][0] < str[0]){
				res += pow(size, str.length() - 1);
				//cout<<"<:" << str[0] << "\t"<<pow(size, str.length() - 1)<<endl;
				/*
				for (int i = 1; i <= str.length() - 1; i++){
				res += pow(size, i);
				}
				*/
			}
			else if (D[i][0] == str[0]){
				res += help(D, str.substr(1));
				//cout<<"=:"<<str[0]<<"\t"<< help(D, str.substr(1))<<endl;
			}
			else{
				break;
			}
		}
		return res;
	}

	int atMostNGivenDigitSet(vector<string>& D, int N) {
		if (N <= 0 || D.size() == 0)
			return 0;
		int res = 0;
		string str = to_string(N);
		int n = str.length();
		size = D.size();
		if (n == 1){
			for (int i = 0; i < D.size(); i++){
				if (D[i][0] <= str[0]){
					res++;
				}
				else{
					break;
				}
			}
			return res;
		}
		for (int i = 1; i <= n - 1; i++){
			res += pow(size, i);
			//cout<<"res"<<res<<endl;
		}
		res += help(D, str);
		return res;
	}
};