#include<queue>
#include<stack>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> m;//´æ´¢Ð¡µÄÕ»
	stack<int> s;

	MinStack() {
		
	}

	void push(int x) {
		s.push(x);
		if (m.empty()){
			m.push(x);
		}
		else{
			if (x <= m.top()){
				m.push(x);
			}
		}
	}

	void pop() {
		int t = s.top();
		s.pop();
		if (t == m.top())
			m.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return m.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/