#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>

using namespace std;


//Wrong Answer
class RangeModule {
public:
	struct Interval{
		int left, right;
		Interval(int l = 0, int r = 0) :left(l), right(r){}
	};

	vector<Interval> vec;

	RangeModule() {

	}

	void addRange(int left, int right) {
		vector<Interval> temp;
		for (int i = 0; i < vec.size(); i++){
			if (left > vec[i].right || right < vec[i].left){
				temp.push_back(vec[i]);
			}
			else{
				while (i < vec.size() && left <= vec[i].left && right >= vec[i].right){
					i++;
				}
				if (i == vec.size()){
					temp.push_back(Interval(left, right));
				}
				else{
					if (right >= vec[i].left){
						temp.push_back(Interval(left, max(right, vec[i].right)));
					}
					else{
						temp.push_back(Interval(left, right));
						i--;
					}
				}
			}
		}
		swap(temp, vec);
		cout << "add:" << endl;
		for (int i = 0; i < vec.size(); i++){
			cout << vec[i].left << "\t" << vec[i].right << endl;
		}
	}

	bool queryRange(int left, int right) {
		int low = 0;
		int high = vec.size() - 1;
		while (low <= high){
			int mid = (low + high) >> 1;
			if (left >= vec[mid].right){
				low = mid + 1;
			}
			else if (right <= vec[mid].left){
				high = mid - 1;
			}
			else{
				return left <= vec[mid].left && right >= vec[mid].right;
			}
		}
		return false;
	}

	void removeRange(int left, int right) {
		vector<Interval> temp;
		for (int i = 0; i < vec.size(); i++){
			if (left > vec[i].right || right < vec[i].left){
				temp.push_back(vec[i]);
			}
			else{
				while (i < vec.size() && left <= vec[i].left && right >= vec[i].right){
					i++;
				}
				if (i == vec.size()){
					continue;
				}
				else{
					if (left > vec[i].left){
						temp.push_back(Interval(vec[i].left, left));
					}
					if (right >= vec[i].left){
						temp.push_back(Interval(right, vec[i].right));
					}
					else{
						i--;
					}
				}
			}
		}
		swap(temp, vec);
		cout << "remove:" << endl;
		for (int i = 0; i < vec.size(); i++){
			cout << vec[i].left << "\t" << vec[i].right << endl;
		}
	}
};

/**
* Your RangeModule object will be instantiated and called as such:
* RangeModule obj = new RangeModule();
* obj.addRange(left,right);
* bool param_2 = obj.queryRange(left,right);
* obj.removeRange(left,right);
*/