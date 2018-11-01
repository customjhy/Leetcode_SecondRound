#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int flag = 0;
	int i;
	for (i = 0; i < nums.size(); i++){
		while (flag < nums.size() - 1 && nums[flag] == 0){
			flag++;
		}
		nums[i] = nums[flag];
		flag++;
		if (flag == nums.size()){
			break;
		}
	}
	i++;
	while (i < nums.size()){
		nums[i] = 0;
		i++;
	}
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
//	moveZeroes(num);
//
//	for (i = 0; i < num.size(); i++){
//		cout << num[i] << "   ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}