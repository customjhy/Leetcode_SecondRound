//#include<iostream>
//#include<string>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<unordered_map>
//#include<deque>
//#include<functional>
//#include<algorithm>
//
//using namespace std;
//
//class LRUCache {
//public:
//	unordered_map<int, int> m;
//	deque<int> de;
//	int size;
//
//	LRUCache(int capacity) {
//		size = capacity;
//		de.clear();
//		m.clear();
//	}
//
//	int get(int key) {
//		if (m.find(key) == m.end())
//			return -1;
//		
//	}
//
//	void put(int key, int value) {
//		if (m.find(key) != m.end()){
//			de.erase(key);
//			de.push_back(key);
//			m[key] = value;
//		}
//		else{
//			m[key] = value;
//			de.push_back(key);
//			if (de.size() > size){
//				int temp = de.front();
//				de.pop_front();
//				m.erase(temp);
//			}
//		}
//	}
//};
//
///**
//* Your LRUCache object will be instantiated and called as such:
//* LRUCache obj = new LRUCache(capacity);
//* int param_1 = obj.get(key);
//* obj.put(key,value);
//*/