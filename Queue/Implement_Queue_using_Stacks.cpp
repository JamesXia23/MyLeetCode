#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
	stack<int> s, q;
	/** Initialize your data structure here. */
	MyQueue() {
		
	}
	
	/** Push element x to the back of queue. */
	void push(int x) {
		s.push(x);
	}
	
	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int temp = peek();
		q.pop();
		return temp;		
	}
	
	/** Get the front element. */
	int peek() {
		if (!q.empty()) {
			return q.top();
		}
		while (!s.empty()) {
			q.push(s.top());
			s.pop();
		}
		return q.top();
	}
	
	/** Returns whether the queue is empty. */
	bool empty() {
		return (s.empty() && q.empty());
	}
};
int main(int argc, char *argv[]) {
	
}

/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

题意:使用栈来实现队列
思路:使用两个栈,s栈,q栈
	当push时,直接push进s栈
	当peek时,如果q栈为空,则将s栈中元素倒入q栈中,然后返回栈顶即可
			如果q栈不为空,直接返回栈顶即可
	当pop时,如果q栈为空,则将s栈中元素倒入q栈中,然后弹出s栈栈顶
			如果q栈不为空,直接弹出栈顶即可
	当empty时,只有当s和q两个栈都空了,结果才为空
*/