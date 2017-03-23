#include <iostream>
#include <stack>
using namespace std;

int getBottom(stack<int> &s);
void reverseStack(stack<int> &s);

int main(int argc, char *argv[]) {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	if (s.empty()) {
		return 1;
	}
	reverseStack(s);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
int getBottom(stack<int> &s){
	int temp = s.top();
	s.pop();
	if (s.empty()) {
		return temp;
	}
	int bottom = getBottom(s);
	s.push(temp);
	return bottom;
}
void reverseStack(stack<int> &s){
	int bottom = getBottom(s);
	if (s.empty()) {
		s.push(bottom);
		return ;
	}
	reverseStack(s);
	s.push(bottom);
}

/*
只用递归操作实现栈的逆序,不申请额外辅助栈
思路:先实现一个能取出栈顶元素的递归函数
		步骤: 1.弹出栈顶,如果栈空了,那这个就是栈底,直接返回,如果栈不空,执行2.
			 2.继续递归找栈底,
			 3.将刚才弹出的数重新压回栈中.(故,整个过程中只有栈底没有重新压回栈中,而且顺着递归函数一路返回)
	主函数中:
		调用函数拿到栈底,然后递归,每层递归都拿出栈底,直到栈顶被拿出,栈空了,则将栈顶重新压入栈,然后返回上一层递归,依次压回
*/