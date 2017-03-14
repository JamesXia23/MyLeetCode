#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next) {
			return head;
		}
		ListNode smallerList(-1), remainList(-1), *smTail = &smallerList, *reTail = &remainList, *now = head;
		while (now) {
			if (now->val < x) {
				smTail->next = now;
				smTail = smTail->next;
				now = now->next;
				smTail->next = nullptr;
			} else {
				reTail->next = now;
				reTail = reTail->next;
				now = now->next;
				reTail->next = nullptr;
			}
		}
		smTail->next = remainList.next;
		return smallerList.next;
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

题意:给定一个数字,将小于该数字的节点移动至链表前端,大于等于该值的节点移动至后端
解答:使用两个链表,第一个链表保存那些小于节点,第二个保存剩余节点,最后将两个链表合并即可
*/