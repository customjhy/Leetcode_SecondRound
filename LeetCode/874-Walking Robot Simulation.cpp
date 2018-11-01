#include<iostream>
#include<vector>
#include<set>
#include<math.h>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	void turn(int& dir, int num){//north--4, west--3, south--2, east--1
		if (num == -2){
			dir--;
			if (dir == 0)
				dir = 4;
		}
		else if (num == -1){
			dir++;
			if (dir == 5)
				dir = 1;
		}
	}

	string convert(int x, int y){
		return to_string(x) + " " + to_string(y);
	}

	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		set<string> obstacle;
		for (int i = 0; i < obstacles.size(); i++){
			obstacle.insert(convert(obstacles[i][0], obstacles[i][1]));
		}
		int res = 0;
		int dir = 4;
		int x = 0;
		int y = 0;
		int postX = 0;
		int postY = 0;
		for (int comm : commands){
			if (comm < 0){
				turn(dir, comm);
				continue;
			}
			for (int i = 0; i < comm; i++){
				postX = x;
				postY = y;
				if (dir == 4){
					postY++;
				}
				else if (dir == 3){
					postX--;
				}
				else if (dir == 2){
					postY--;
				}
				else{
					postX++;
				}
				if (obstacle.find(convert(postX, postY)) != obstacle.end()){
					break;
				}
				x = postX;
				y = postY;
				res = max(res, x * x + y * y);
			}
		}
		return res;
	}
};