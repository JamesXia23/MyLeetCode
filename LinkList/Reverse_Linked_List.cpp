#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) {
			return head;
		}
		stack<int> s;
		ListNode *p = head;
		while (p) {
			s.push(p->val);
			p = p->next;
		}
		
		p = head;
		while (p) {
			p->val = s.top();
			s.pop();
			p = p->next;
		}
		return head;
	}
};
int main(int argc, char *argv[]) {
	ListNode head(1), *p = &head;
	Solution s;
	
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(5);
	
	p = &head;
	p = s.reverseList(p);
	while (p) {
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}
/*
Reverse a singly linked list.
旋转一个单链表
*/