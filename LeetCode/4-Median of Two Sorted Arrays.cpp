#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2, nums1);
		int m = nums1.size();
		int n = nums2.size();
		int low = 0;
		int high = m;
		while (low <= high){
			int i = (low + high) / 2;
			int j = (m + n + 1) / 2 - i;
			int leftX = i == 0 ? INT_MIN : nums1[i - 1];
			int rightX = i == m ? INT_MAX : nums1[i];
			int leftY = j == 0 ? INT_MIN : nums2[j - 1];
			int rightY = j == n ? INT_MAX : nums2[j];
			if (leftX <= rightY && leftY <= rightX){
				if ((m + n) % 2 == 1){
					return max(leftX, leftY);
				}
				else{
					return (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
				}
			}
			else if (leftX > rightY){
				high = i - 1;
			}
			else {
				low = i + 1;
			}
		}
		return 0.0;
	}
};