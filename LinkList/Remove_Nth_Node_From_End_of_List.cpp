#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) {
			return head;
		}
		ListNode *fast = head, *slow = head;
		
		for (int i = 0; i < n; i++) {
			fast = fast->next;
		}
		if (!fast) {//表示要删除的是头节点(倒数第n个)
			return head->next;
		}
		while (fast->next) {//跳出循环时,slow指针指向了要删除节点的上一个节点
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;
	}
};
int main(int argc, char *argv[]) {
	
}

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

	Given linked list: 1->2->3->4->5, and n = 2.

	After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

题意:删除链表倒数第n个节点
	例如:1->2->3->4->5, n = 2,返回链表1->2->3->5
思路:
	使用两个指针,第一个指针先走n步,然后第二个指针再走,直到第一个指针走完第二个指针所在位置就是倒数第n个位置,删除即可(也就是说,第一个指针走到最后一个节点时,第二个指针走到了要删除节点的上一个节点的位置,直接将其指向要删除节点的下一个节点即可).
*/