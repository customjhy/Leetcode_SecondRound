#include<iostream>
#include<vector>

using namespace std;

bool isHappy(int n) {
	if (n == 1)return true;
	vector<int> record;
	int sum, temp;
	while (1){
		sum = 0;
		while (n > 0){
			temp = n % 10;
			n = n / 10;
			sum += temp*temp;
		}
		if (sum == 1)return true;
		for (int i = 0; i < record.size(); i++){
			if (sum == record[i])return false;
		}
		record.push_back(sum);
		n = sum;
	}
}
//
//int main(){
//	int n;
//	cin >> n;
//	cout << (bool)isHappy(n) << endl;
//
//	system("pause");
//	return 0;
//}