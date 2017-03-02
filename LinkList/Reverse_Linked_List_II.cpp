#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//不会出现空链表
//		while(!head){
//			return head;
//		}
		ListNode readHead(-1), *p = &readHead;//定义一个真正的头结点
		readHead.next = head;
		int i;
		
		for (i = 0; i < m-1; i++) {//将链表遍历至pm的先驱节点
			p = p->next;
		}
		ListNode *pre = p;//保存先驱节点pre
		ListNode *pm = pre->next;//保存pm
		for(i = m+1, p=pm->next; i <= n; i++){//p移动至pm+1
			ListNode *tmp = p;//保存反转节点
			pm->next = tmp->next;//pm挂载反转节点的后续节点
			tmp->next = pre->next;//反转节点挂载pre的后续节点
			pre->next = tmp;//pre挂载反转节点
			
			p = pm->next;	//新反转节点,因为pm永远挂载下一个反转节点
		}
		return readHead.next;
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

处理链表反转的思路:令第m个数为pm,遍历链表至pm的先驱节点pre,
				保存pm+1,
				将pm+1的next挂载到pm之后,
				pre的next挂载到pm+1之后,
				将pm+1挂载到pre之后.
				总结就是:	1.每次先保存要反转的结点									//前两步保证反转节点的后续节点都在pm之后
						2.将此节点的后续节点挂载至pm上		(用pm来挂后续结点)
						3.将pre的后序节点挂载至反转节点上	(反转节点来挂pre的后续结点)	//后两步是经典的头插法
						4.用pre来挂载反转节点				(pre来挂反转节点)
						
*/