#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
	int calPoints(vector<string>& opsa) {
		stack<int> s;
		for (unsigned int i = 0; i < opsa.size(); i++){
			if (opsa[i].compare("C") == 0){
				s.pop();
			}
			else if (opsa[i].compare("D") == 0){
				int temp = s.top();
				s.push(2 * temp);
			}
			else if (opsa[i].compare("+") == 0){
				int a = s.top();
				s.pop();
				int b = s.top();
				s.push(a);
				s.push(a + b);
			}
			else{
				int temp = stoi(opsa[i]);
				s.push(temp);
			}
		}
		int res = 0;
		while (!s.empty()){
			res += s.top();
			s.pop();
		}
		return res;
	}
};