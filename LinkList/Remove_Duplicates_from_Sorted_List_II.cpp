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
		if(!head || !head->next) {
			return head;
		}
		ListNode readHead(head->val-1);
		readHead.next = head;
		ListNode *pre = &readHead, *i = head->next, *j = head;
		
		while (i) {
			if (i->val == j->val) {
				if (i->next) {//判断i是否是最后一个节点,
					i = i->next;
					continue;
				}else {//如果是,直接将i-j这一段全部删除
					pre->next = nullptr;
					break;
				}
			}else {
				if (j->next != i) {//说明出现了相同的节点,需要删除j
					pre->next = i;
					j = i;
					i = i->next;
				}else {//说明没有出现相同的节点
					pre = pre->next;
					j = j->next;
					i = i->next;
				}
			}
		}
		return readHead.next;
		
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
题意:删除所有有重复的节点
思路:与第一题一样,只是增加了一个指针来指向j的前方,用来删除有相同元素的j
*/