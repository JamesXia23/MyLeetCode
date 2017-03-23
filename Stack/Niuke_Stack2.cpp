#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char *argv[]) {
	stack<int> sortStack, assistStack;
	sortStack.push(4);
	sortStack.push(7);
	sortStack.push(2);
	sortStack.push(3);
	sortStack.push(1);
	sortStack.push(5);
	
	while (!sortStack.empty()) {
		int sortTop = sortStack.top();
		sortStack.pop();
		
		if (assistStack.empty() || sortTop < assistStack.top()) {
			assistStack.push(sortTop);
		}else {
			while (!assistStack.empty()) {
				sortStack.push(assistStack.top());
				assistStack.pop();
			}
			assistStack.push(sortTop);
			while (!sortStack.empty() && sortStack.top() < assistStack.top()) {
				assistStack.push(sortStack.top());
				sortStack.pop();
			}
		}
	}
	while (!assistStack.empty()) {
		cout << assistStack.top() << endl;
		assistStack.pop();
	}
}
/*
只允许使用一个辅助栈,实现栈中元素的排序
思路:原栈栈顶弹出,如果辅助栈为空或者栈顶大于弹出数,将弹出数压入辅助栈,否则,将辅助栈中的元素依次弹出并压入原栈,再将弹出数压入辅助栈,然后原栈的数重新压回辅助栈
*/