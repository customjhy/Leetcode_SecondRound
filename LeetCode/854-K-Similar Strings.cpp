#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
#include<functional>

using namespace std;

class Solution {
public:
	int kSimilarity(string A, string B) {
		int res = 0;
		int len = A.length();
		for (int i = 0; i < len; i++){
			if (A[i] != B[i]){
				for (int j = i + 1; j < len; j++){
					if (A[j] == B[i] && A[i] == B[j]){
						swap(A[i], A[j]);
						res++;
						break;
					}
				}
			}
		}
		queue<string> q;
		q.push(A);
		unordered_set<string> s;
		s.insert(A);

		string temp;
		while (!q.empty()){
			int size = q.size();
			while (size-- > 0){
				temp = q.front();
				q.pop();
				if (temp == B){
					return res;
				}
				for (int i = 0; i < len; i++){
					if (temp[i] != B[i]){
						for (int j = i + 1; j < len; j++){
							if (temp[j] == B[i] && temp[j] != B[j]){
								swap(temp[i], temp[j]);
								if (s.find(temp) == s.end()){
									s.insert(temp);
									q.push(temp);
								}
								swap(temp[i], temp[j]);
							}
						}
					}
				}
			}
			res++;
		}
		return -1;
	}
};

//"abc"
//"bca"

//string A = "abcdefghijklmn";
//string B = "bcdefghijklmna";

//"cdebcdeadedaaaebfbcf"
//"baaddacfedebefdabecc"
//12

//int main(){
//	string A = "cdebcdeadedaaaebfbcf";
//	string B = "baaddacfedebefdabecc";
//	cout << (new Solution())->kSimilarity(A, B) << endl;
//
//	system("Pause");
//	return 0;
//}
//
