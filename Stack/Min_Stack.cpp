#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> dataStack, minStack;
	MinStack() {
		
	}
	
	void push(int x) {
		dataStack.push(x);
		if (minStack.empty()) {
			minStack.push(x);
			return ;
		}
		if (minStack.top() < x) {
			minStack.push(minStack.top());
		} else {
			minStack.push(x);
		}
	}
	
	void pop() {
		minStack.pop();
		dataStack.pop();
	}
	
	int top() {
		return dataStack.top();
	}
	
	int getMin() {
		return minStack.top();
	}
};
int main(int argc, char *argv[]) {
	
}

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
题意:设计一个栈,除了实现原来的栈的功能外,还实现了得到当前栈中最小值的操作
思路:使用两个栈dataStack,minStack,有两种方法:
	第一种方法:dataStack中压入需要保留的元素,minStack压入当前栈中的最小值
				例如:3 4 5 1 2 1
					dataStack中:3 4 5 1 2 1
					minStack中:3 3 3 1 1 1
*/