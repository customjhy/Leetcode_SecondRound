#include<vector>

using namespace std;

class MyCircularDeque {
public:
	vector<int> vec;
	int start;
	int end;
	int mod;

	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		vec.resize(k + 1);
		start = 0;
		end = 0;
		mod = k + 1;
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (isFull())
			return false;
		start--;
		if (start == -1)
			start = mod - 1;
		vec[start] = value;
		return true;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (isFull())
			return false;
		vec[end] = value;
		end = (end + 1) % mod;
		return true;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (isEmpty())
			return false;
		start = (start + 1) % mod;
		return true;
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (isEmpty())
			return false;
		end--;
		if (end == -1){
			end = mod - 1;
		}
		return true;
	}

	/** Get the front item from the deque. */
	int getFront() {
		if (isEmpty())
			return -1;
		return vec[start];
	}

	/** Get the last item from the deque. */
	int getRear() {
		if (isEmpty())
			return -1;
		int temp = end - 1;
		if (temp == -1)
			temp = mod - 1;
		return vec[temp];
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return start == end;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return (end + 1) % mod == start;
	}
};

/**
* Your MyCircularDeque object will be instantiated and called as such:
* MyCircularDeque obj = new MyCircularDeque(k);
* bool param_1 = obj.insertFront(value);
* bool param_2 = obj.insertLast(value);
* bool param_3 = obj.deleteFront();
* bool param_4 = obj.deleteLast();
* int param_5 = obj.getFront();
* int param_6 = obj.getRear();
* bool param_7 = obj.isEmpty();
* bool param_8 = obj.isFull();
*/