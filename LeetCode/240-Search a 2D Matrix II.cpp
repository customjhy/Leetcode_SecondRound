#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		int left = 0;
		int up = 0;
		int right = matrix[0].size();
		int down = matrix.size();
		return divide(matrix, target, left, right, up, down);
	}

	bool divide(vector<vector<int>>& matrix, int target, int left, int right, int up, int down){
		if (left >= right || up >= down)
			return false;
		int midRow = (up + down) >> 1;
		int midCol = (left + right) >> 1;
		bool res = false;
		if (matrix[midRow][midCol] == target)
			return true;
		if (matrix[midRow][midCol] < target){
			if (divide(matrix, target, midCol + 1, right, up, midRow + 1))
				return true;
			if (divide(matrix, target, left, midCol + 1, midRow + 1, down))
				return true;
			if (divide(matrix, target, midCol + 1, right, midRow + 1, down))
				return true;
			return false;
		}
		else{
			if (divide(matrix, target, left, midCol, up, midRow))
				return true;
			if (divide(matrix, target, midCol, right, up, midRow))
				return true;
			if (divide(matrix, target, left, midCol, midRow, down))
				return true;
			return false;
		}
		return false;

	}
};