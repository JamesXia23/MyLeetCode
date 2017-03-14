#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) {
			return nullptr;
		}
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast) {
				//将fast指向头结点重新走,现在一次只走一步
				fast = head;
				while (slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return nullptr;
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

题意:在求链表是否为环的基础上,增加了求解环的起点
思路:假设表头到环起点距离为a,环起点相遇点为b,环长度为r,则slow指针路程为s=a+b,fast指针路程为2s=s+n*r(n为fast指针在环中转的圈数),则a+b=n*r => a=n*r-b=(n-1)*r+r-b,而r-b刚好是相遇点走到环起点的路程,所以只要在相遇时,使用另一个指针从起点出发,slow指针继续前行,则slow指针与另一个指针相遇的点就是环起点
*/