#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<functional>

using namespace std;

//Solution1 : WA
//class Solution {
//public:
//	string crackSafe(int n, int k) {
//		if (n == 0){
//			return "";
//		}
//		string res = "";
//		if (n == 1){
//			for (int i = 0; i < k; i++){
//				res += to_string(i);
//			}
//			return res;
//		}
//		vector<set<string>> s(n);
//		for (int i = 0; i < k; i++){
//			s[1].insert(to_string(i));
//		}
//		for (int i = 2; i < n; i++){
//			for (string iter : s[i - 1]){
//				for (char c = '0'; c < '0' + k; c++){
//					s[i].insert(iter + c);
//				}
//			}
//		}
//		set<string> has;
//		for (string iter : s[n - 1]){
//			for (char c = '0'; c < '0' + k; c++){
//				has.insert(iter + c);
//			}
//		}
//		for (int i = 0; i < n; i++){
//			res += "0";
//		}
//		has.erase(res);
//		while (!has.empty()){
//			bool flag = false;
//			for (int len = n - 1; len >= 1; len--){
//				string str = res.substr(res.size() - len, len);
//				for (string iter : s[n - len]){
//					if (has.find(str + iter) != has.end()){
//						str += iter;
//						res += iter;
//						has.erase(str);
//						flag = true;
//						break;
//					}
//				}
//				if (flag)
//					break;
//			}
//			if (flag)
//				continue;
//			string temp = *(has.begin());
//			res += temp;
//			has.erase(temp);
//		}
//		return res;
//	}
//};

//Solution2 : Greedy & dfs & backtrace 
class Solution {
public:
	string crackSafe(int n, int k) {
		string res = "";
		int goal = pow(k, n);
		//cout << goal << endl;
		set<string> visit;
		for (int i = 0; i < n; i++){
			res += "0";
		}
		visit.insert(res);
		dfs(res, goal, visit, n, k);
		return res;
	}

	bool dfs(string& res, int goal, set<string>& visit,int n, int k){
		if (goal == visit.size())
			return true;
		string temp = res.substr(res.length() - n + 1, n - 1);
		for (char c = '0'; c < '0' + k; c++){
			temp += c;
			//cout << "temp" << temp << endl;
			if (visit.find(temp) == visit.end()){
				visit.insert(temp);
				res += c;
				if (dfs(res, goal, visit, n, k))
					return true;
				res.resize(res.length() - 1);
				visit.erase(temp);
			}
			temp.resize(temp.length() - 1);
		}
		return false;
	}
};

//int main(){
//	int n = 1;
//	int k = 3;
//	cout << (new Solution())->crackSafe(n, k);
//	
//	system("Pause");
//	return 0;
//}
//
