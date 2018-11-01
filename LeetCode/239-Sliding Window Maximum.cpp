#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		priority_queue<int> prio;
		unordered_map<int, int> m;
		vector<int> res;
		for (int i = 0; i < k - 1; i++){
			prio.push(nums[i]);
			m[nums[i]]++;
		}
		for (int i = k - 1; i < nums.size(); i++){
			m[nums[i]]++;
			prio.push(nums[i]);
			int temp = prio.top();
			while (m.find(temp) == m.end() || m[temp] == 0){
				prio.pop();
				temp = prio.top();
			}
			res.push_back(temp);
			m[nums[i - k]]--;
		}
		return res;
	}
};
//
//int main(){
//	priority_queue<int> prio;
//	prio.push(1);
//	prio.push(1);
//	prio.push(2);
//	prio.push(1);
//	while (!prio.empty()){
//		cout << prio.top();
//		prio.pop();
//	}
//
//	system("pause");
//	return 0;
//}