#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
	int left = 0;
	int right = numbers.size() - 1;
	while (left < right){
		if (numbers[left] + numbers[right] == target){
			vector<int> result{ left + 1, right + 1 };
			return result;
		}
		else if (numbers[left] + numbers[right] > target){
			right--;
		}
		else{
			left++;
		}
	}
	return vector<int>();
}
//
//int main(){
//	vector<int> num;
//	int i = 1;
//	while (i != -1){
//		cin >> i;
//		num.push_back(i);
//	}
//	num.pop_back();
//	int target;
//	cin >> target;
//	vector<int> result = twoSum(num, target);
//	cout << result[0] << "   " << result[1] << endl;
//
//	system("pause");
//	return 0;
//}