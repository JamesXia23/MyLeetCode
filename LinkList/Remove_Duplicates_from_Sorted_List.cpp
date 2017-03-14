#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode *i = head, *j = head;//j来指向最后链表的最后一个元素,已知头结点肯定会保存
		while(i->next) {
			if (j->val == i->next->val) {
				i->next = i->next->next;
			}else {
				j = j->next;
				i = i->next;
			}
		}
		return head;
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

题意:删除链表中值重复的节点
思路:与数组类似
*/