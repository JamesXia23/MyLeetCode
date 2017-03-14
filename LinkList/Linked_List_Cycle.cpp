#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head || !head->next) {
			return false;
		}
		ListNode *fast = head, *slow = head;
		
		while (fast->next && fast->next->next) {
			//快指针移动两格
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				return true;
			}
		}
		return false;
	}
};
int main(int argc, char *argv[]) {
	
}

/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
题意:判断指针是否有环
思路:使用快慢两个指针,一个指针每次移动一格,一个每次移动两格如果两个指针可以再次相遇就说明有环,如果块指针到了链表尾,则没有环
*/