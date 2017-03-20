#include <iostream>
#include <queue>
using namespace std;

/*
class MyStack {
public:
	queue<int> q;
	int count;
	int stackTop;
	
	MyStack() {
		count = 0;
		stackTop = 0;
	}
		
	
	void push(int x) {
		q.push(x);
		count++;
		stackTop = x;
	}
		
	
	int pop() {
		for (int i = 0; i < count-1; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
			stackTop = temp;
		}
		int temp = q.front();
		q.pop();
		count--;
		return temp;
	}
		
	
	int top() {
		return stackTop;
	}
		
	
	bool empty() {
		return q.empty();
	}
};
*/
class MyStack {
public:
	queue<int> q;
	
	/** Initialize your data structure here. */
	MyStack() {
		
	}
		
	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
		for (int i = 0; i < q.size() - 1; i++) {
			q.push(q.front());
			q.pop();
		}
	}
		
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int temp = q.front();
		q.pop();
		return temp;
	}
		
	/** Get the top element. */
	int top() {
		return q.front();
	}
		
	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

int main(int argc, char *argv[]) {

}

/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

题意:使用队列来实现栈,要求实现栈的所有操作
思路:
	需要一个变量top记录栈顶元素
	每次push,栈顶指向此元素,直接调用队列的push
	每次top,直接返回栈顶元素变量top
	每次empty,直接调用队列的empty方法
	每次pop,将队头出队,并栈顶指向该元素,然后再将该元素入队,重复q.size()-1次,此时队头元素就是原栈顶元素,将其出队列
	push top empty O(1), pop O(n)
另一个思路:
	每次push,先将元素入队,然后将他前面的数全部出队再入队,则此时刚入队的元素就到队头,也就是栈顶了
	push O(n), pop top empty O(1)
	
*/