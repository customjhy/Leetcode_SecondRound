#include<iostream>
#include<vector>

using namespace std;

struct node{
	int number;
	int count;
	node(int x) : number(x), count(1) {}
};

int majorityElement(vector<int>& nums) {
	vector<node> vect;
	int flag = 0;
	int j = 0;
	int size = nums.size();
	for (int i = 0; i < size; i++){
		flag = 0;
		for (j = 0; j < vect.size(); j++){
			if (vect[j].number == nums[i]){
				flag++;
				vect[j].count++;
				break;
			}
		}
		if (flag == 0){
			node temp(nums[i]);
			vect.push_back(temp);
		}
	}
	size = size / 2;
	for (j = 0; j < vect.size(); j++){
		if (vect[j].count>size)
			return vect[j].number;
	}
	return -1;
}
//
//int main(){
//	vector<int> number;
//	int num = 1;
//	while (num != -1){
//		cin >> num;
//		number.push_back(num);
//	}
//	number.pop_back();
//	cout << majorityElement(number) << endl;
//
//	system("pause");
//	return 0;
//
//}
