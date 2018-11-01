#include<vector>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<unordered_set>
#include<iostream>

using namespace std;

/*Solution1 : dfs--TLE
class Solution {
public:
	int res = INT_MAX;
	int m, n;
	int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

	bool valid(int i, int j){
		return i >= 0 && i < m && j >= 0 && j < n;
	}

	void dfs(vector<string>& grid, vector<vector<bool> >& visit, int row, int col, unordered_set<char>& key, const int& target, int step){
		if (key.size() == target){
			res = min(res, step);
			return;
		}
		if (grid[row][col] == '#'){
			return;
		}
		else if (grid[row][col] == '.' || grid[row][col] == '@'){
			visit[row][col] = true;
			for (int i = 0; i < 4; i++){
				int r = row + dir[i][0];
				int c = col + dir[i][1];
				if (valid(r, c) && !visit[r][c]){
					dfs(grid, visit, r, c, key, target, step + 1);
				}
			}
			visit[row][col] = false;
		}
		else if (grid[row][col] >= 'a'&& grid[row][col] <= 'f'){
			char c = grid[row][col];
			grid[row][col] = '.';
			key.insert(c);
			vector<vector<bool> > newVisit(m, vector<bool>(n, false));
			dfs(grid, newVisit, row, col, key, target, step);
			key.erase(c);
			grid[row][col] = c;
		}
		else if (grid[row][col] >= 'A'&& grid[row][col] <= 'F'){
			if (key.find(grid[row][col] - 'A' + 'a') != key.end()){
				visit[row][col] = true;
				for (int i = 0; i < 4; i++){
					int r = row + dir[i][0];
					int c = col + dir[i][1];
					if (valid(r, c) && !visit[r][c]){
						dfs(grid, visit, r, c, key, target, step + 1);
					}
				}
				visit[row][col] = false;
			}
			else{
				return;
			}
		}
	}

	int shortestPathAllKeys(vector<string>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		m = grid.size();
		n = grid[0].size();
		int startR = 0;
		int startC = 0;
		int target = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (grid[i][j] == '@'){
					startR = i;
					startC = j;
				}
				else if (grid[i][j] >= 'a' && grid[i][j] <= 'f'){
					target++;
				}
			}
		}
		if (target == 0)
			return 0;
		vector<vector<bool> > visit(m, vector<bool>(n, false));
		unordered_set<char> key;
		dfs(grid, visit, startR, startC, key, target, 0);
		return res == INT_MAX ? -1 : res;
	}
};*/


//Solution2 : BFS--AC
class Solution {
public:
	struct state{
		int key;
		int row;
		int col;
		state(int k = 0, int r = 0, int c = 0) :key(k), row(r), col(c){}
	};

	int m, n;

	bool valid(int i, int j){
		return i >= 0 && i < m && j >= 0 && j < n;
	}

	int shortestPathAllKeys(vector<string>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		m = grid.size();
		n = grid[0].size();
		int startR = 0;
		int startC = 0;
		int target = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (grid[i][j] == '@'){
					startR = i;
					startC = j;
				}
				else if (grid[i][j] >= 'a' && grid[i][j] <= 'f'){
					target = max(target, grid[i][j] - 'a' + 1);
				}
			}
		}
		if (target == 0)
			return 0;
		int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		unordered_set<int> s;
		queue<state> q;
		q.push(state(0, startR, startC));
		s.insert(0 * 10000 + startR * 100 + startC);
		int res = 0;
		state temp;
		while (!q.empty()){
			int size = q.size();
			while (size-- > 0){
				temp = q.front();
				q.pop();
				for (int i = 0; i < 4; i++){
					int k = temp.key;
					int r = temp.row + dir[i][0];
					int c = temp.col + dir[i][1];
					if (k == (1 << target) - 1){
						return res;
					}
					if (!valid(r, c))
						continue;
					if (grid[r][c] == '#')
						continue;
					if (grid[r][c] >= 'a' && grid[r][c] <= 'f'){
						k = k | (1 << (grid[r][c] - 'a'));
					}
					if (grid[r][c] >= 'A' && grid[r][c] <= 'F'){
						if ((k & (1 << (grid[r][c] - 'A'))) == 0){
							continue;
						}
					}
					if (s.find(k * 10000 + r * 100 + c) != s.end()){
						continue;
					}
					else{
						s.insert(k * 10000 + r * 100 + c);
						q.push(state(k, r, c));
					}
				}
			}
			res++;
		}
		return -1;
	}
};

//
//
//int main(){
//	vector<string> grid{ ".##..##..B", "##...#...#", "..##..#...", ".#..#b...#", "#.##.a.###", ".#....#...", ".##..#.#..", ".....###@.", "..........", ".........A" };
//	cout << (new Solution())->shortestPathAllKeys(grid) << endl;
//	system("Pause");
//	return 0;
//}