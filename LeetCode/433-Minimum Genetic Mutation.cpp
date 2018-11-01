#include<string>
#include<algorithm>
#include<unordered_set>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string> has;
		for (string b : bank){
			has.insert(b);
		}
		if (has.find(end) == has.end())
			return -1;
		int level = 1;
		queue<string> q;
		q.push(start);
		string temp;
		char ch[] = { 'A', 'C', 'G', 'T' };
		while (!q.empty()){
			int size = q.size();
			while (size-- > 0){
				temp = q.front();
				q.pop();
				for (int i = 0; i < 8; i++){
					char c = temp[i];
					for (int j = 0; j < 4; j++){
						if (ch[j] == c)
							continue;
						temp[i] = ch[j];
						if (has.find(temp) != has.end()){
							if (temp == end)
								return level;
							q.push(temp);
							has.erase(temp);
						}
					}
					temp[i] = c;
				}
			}
			level++;
		}
		return - 1;
	}
};