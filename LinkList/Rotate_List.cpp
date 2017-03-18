#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) {
			return head;
		}
		int len = 0;
		ListNode *p = head;
		
		while(p){
			len++;
			if (!p->next) {//最后一个节点
				p->next = head;
				break;
			}
			p = p->next;
		}
		p = head;
		k %= len;
		k = len - k - 1;
		while (k--) {//遍历到要移动的节点的前一个节点
			p = p->next;
		}
		head = p->next;
		p->next = nullptr;
		
		return head;
	}
};
int main(int argc, char *argv[]) {
	
}

/*
Given a list, rotate the list to the right by k places, where k is non-negative.
For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.
题意:输入一个数,将链表后k位移动到链表头,注意k可能会大于链表长度,所以要先求链表长度
思路:先遍历一遍,记录链表长度,然后将链表尾部连接都头部,接着k%=len,然后再移动len-k步,将链表断开
*/