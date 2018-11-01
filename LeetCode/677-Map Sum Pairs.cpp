#include<string>
#include<unordered_map>

using namespace std;
//
//struct Trie{
//	Trie* ch[26] = {};
//	int sum = 0;
//};
//
//class MapSum {
//public:
//	Trie root;
//	unordered_map<string, int> m;
//	/** Initialize your data structure here. */
//	MapSum() {
//
//	}
//
//	void insert(string key, int val) {
//		Trie* temp = &root;
//		for (int i = 0; i < key.length(); i++){
//			if (temp->ch[key[i] - 'a'] == NULL){
//				temp->ch[key[i] - 'a'] = new Trie();
//			}
//			temp = temp->ch[key[i] - 'a'];
//			temp->sum += val - m[key];
//		}
//		m[key] = val;
//	}
//
//	int sum(string prefix) {
//		Trie* temp = &root;
//		for (int i = 0; i < prefix.length(); i++){
//			if (temp->ch[prefix[i] - 'a'] == NULL)
//				return 0;
//			temp = temp->ch[prefix[i] - 'a'];
//		}
//		return temp->sum;
//	}
//};


/**
* Your MapSum object will be instantiated and called as such:
* MapSum obj = new MapSum();
* obj.insert(key,val);
* int param_2 = obj.sum(prefix);
*/