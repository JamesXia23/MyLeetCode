#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		if (!head) {
//			return head;
//		}
//		stack<int> s;
//		ListNode *p = head;
//		while (p) {
//			s.push(p->val);
//			p = p->next;
//		}
//		
//		p = head;
//		while (p) {
//			p->val = s.top();
//			s.pop();
//			p = p->next;
//		}
//		return head;
//	}
//};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode readHead(-1);//定义一个空头结点
		readHead.next = head;
		ListNode *now = head->next;//记录要反转的点
		while(now){
			ListNode *temp = now->next;//保存要反转的点的后续结点
			now->next = readHead.next;//头插now
			readHead.next = now;
			head->next = temp;	//有原链表的头结点来接管剩下的链表,即保证head永远在已经倒叙过的链表的最后
			now = head->next;//移动now到下一个需要逆序的节点
		}
		return readHead.next;
	}
};
int main(int argc, char *argv[]) {
	ListNode head(1), *p = &head;
	Solution s;
	
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(5);
	
	p = &head;
	p = s.reverseList(p);
	while (p) {
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}
/*
Reverse a singly linked list.
旋转一个单链表
*/