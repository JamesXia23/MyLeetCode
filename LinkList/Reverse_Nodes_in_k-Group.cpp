#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || !head->next || k <= 1) {
			return head;
		}	
		ListNode readHead(-1), *pre = &readHead, *p = head;
		readHead.next = head;
		int count = 0;
		
		while (p) {
			count++;
			if (count == k) {
				ListNode *tempHead = pre->next, *now = tempHead->next;
				count--;//第一个数不用逆转,所以减去一次
				while (count--) {
					tempHead->next = now->next;
					now->next = pre->next;
					pre->next = now;
					
					now = tempHead->next;//向后移动
				}
				count = 0;	//count置0
				pre = tempHead;//更新pre为下一次逆序之前的节点
				p = pre->next;//更新p为下一次逆序的第一个节点
			}else {
				p = p->next;
			}
		}
		return readHead.next;
	}
};
int main(int argc, char *argv[]) {
	ListNode head(1), *readHead = &head;
	head.next = new ListNode (2);
	head.next->next = new ListNode (3);
	head.next->next->next = new ListNode (4);
	Solution s;
	
	readHead = s.reverseKGroup(readHead, 2);
	while (readHead) {
		cout << readHead->val<<endl;
		readHead = readHead->next;
	}
}
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

题意:链表每k个节点逆序,如果不够k个,不逆序
解法:每次记得保存k个节点之前的节点即可
*/