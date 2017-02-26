#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode sum(-1); //头结点
		ListNode *p = &sum;
		int carry = 0;
		
		while (l1 || l2) {
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int tmpSum = (val1 + val2 + carry);
			
			p->next = new ListNode(tmpSum % 10);
			carry = tmpSum / 10;
			
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
			p = p->next;
		}
		if (carry) {
			p->next = new ListNode(1);
		}
		return sum.next;
	}
};
int main(int argc, char *argv[]) {
	ListNode l1(2), l2(5);
	ListNode *p1 = &l1, *p2 = &l2;
	Solution s;
	
	p1->next = new ListNode(4);
	p1 = p1->next;
	p1->next = new ListNode(3);
//	cout << l1.val << l1.next->val << l1.next->next->val;
	p1 = &l1;
//	cout << p1->val << p1->next->val;
//	while (p1 != nullptr) {
//		cout << p1->val;
//		p1 = p1->next;
//	}
	
//	p2->next = new ListNode(6);
//	p2 = p2->next;
	p2->next = new ListNode(4);
	p2 = &l2;
	
	ListNode *p = s.addTwoNumbers(p1, p2);
	return 0;
}
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
整个数字是逆序的,所以注意进位即可
*/