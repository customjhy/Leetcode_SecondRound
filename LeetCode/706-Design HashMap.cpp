#include<iostream>
#include<set>
#include<vector>

using namespace std;

class MyHashMap {
public:
	struct node
	{
		int key;
		int value;
		node(int k, int v){
			key = k;
			value = v;
		}
	};

	/** Initialize your data structure here. */
	MyHashMap() {

	}

	set<int> exist;
	set<int> invalid;
	vector<node> vec;

	/** value will always be non-negative. */
	void put(int key, int value) {
		if (exist.find(key) != exist.end()){
			for (int i = 0; i < vec.size(); i++){
				if (vec[i].key == key){
					vec[i].value = value;
					break;
				}
			}
		}
		else if (invalid.find(key) != invalid.end()){
			for (int i = 0; i < vec.size(); i++){
				if (vec[i].key == key){
					vec[i].value = value;
					invalid.erase(key);
					exist.insert(key);
					break;
				}
			}
		}
		else{
			vec.push_back(node(key, value));
			exist.insert(key);
		}
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		if (exist.find(key) == exist.end())
			return -1;
		for (int i = 0; i < vec.size(); i++){
			if (vec[i].key == key){
				return vec[i].value;
			}
		}
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		if (exist.find(key) != exist.end()){
			exist.erase(key);
			invalid.insert(key);
		}
	}
};

/**
* Your MyHashMap object will be instantiated and called as such:
* MyHashMap obj = new MyHashMap();
* obj.put(key,value);
* int param_2 = obj.get(key);
* obj.remove(key);
*/