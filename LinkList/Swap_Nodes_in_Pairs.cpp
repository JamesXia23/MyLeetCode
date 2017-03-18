#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode readHead(-1), *p = &readHead;
		readHead.next = head;
		
		while (p && p->next && p->next->next) {
			ListNode *first = p->next, *second = p->next->next;
			
			p->next = second;
			first->next = second->next;
			second->next = first;
			p = p->next->next;
		}
		return readHead.next;
	}
};
int main(int argc, char *argv[]) {
	
}

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

题意:两两交换链表节点,因为只是两个,所有直接交换就行,只要记录交换前的节点即可
*/