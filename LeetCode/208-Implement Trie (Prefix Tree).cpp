#include<string>

using namespace std;

class Trie {
public:
	struct TrieNode{
		TrieNode* child[26];
		bool isWord;
	};
	
	TrieNode* root;

	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* temp = root;
		for (int i = 0; i < word.length(); i++){
			int t = word[i] - 'a';
			if (temp->child[t] == NULL){
				temp->child[t] = new TrieNode();
			}
			temp = temp->child[t];
		}
		temp->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* temp = root;
		for (int i = 0; i < word.length(); i++){
			int t = word[i] - 'a';
			if (temp->child[t] == NULL){
				return false;
			}
			temp = temp->child[t];
		}
		return temp->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* temp = root;
		for (int i = 0; i < prefix.length(); i++){
			int t = prefix[i] - 'a';
			if (temp->child[t] == NULL){
				return false;
			}
			temp = temp->child[t];
		}
		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/