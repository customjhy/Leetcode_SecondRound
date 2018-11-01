#include<iostream>
#include<vector>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> result;
	int flag = 1;//record if result contain number
	for (int i = 0; i < nums1.size(); i++){
		flag = 1;
		for (int k = 0; k < result.size(); k++){
			if (nums1[i] == result[k]){
				flag = 0;
				break;
			}
		}
		if (flag){
			for (int j = 0; j < nums2.size(); j++){
				if (nums1[i] == nums2[j]){
					result.push_back(nums1[i]);
					break;
				}
			}
		}
	}
	return result;
}
//
//int main(){
//
//
//
//
//	system("pause");
//	return 0;
//}