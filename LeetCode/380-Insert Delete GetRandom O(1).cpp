#include<vector>
#include<unordered_map>

using namespace std;

class RandomizedSet {
public:
	vector<int> vec;
	unordered_map<int, int> m;
	int size;

	/** Initialize your data structure here. */
	RandomizedSet() {
		size = 0;
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (m.find(val) != m.end())
			return false;
		m[val] = size;
		vec.push_back(val);
		size++;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (m.find(val) == m.end())
			return false;
		int index = m[val];
		m.erase(val);
		vec[index] = vec[size - 1];
		m[vec[index]] = index;
		size--;
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int ran = rand() % size;
		return vec[ran];
	}
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/