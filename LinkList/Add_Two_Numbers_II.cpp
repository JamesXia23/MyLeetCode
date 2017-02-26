#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//栈实现,没啥技术含量
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		stack<int> s1, s2;
//		ListNode sum(-1);//头结点
//		int carry = 0;
//		
//		while (l1) {
//			s1.push(l1->val);
//			l1 = l1->next;
//		}
//		while (l2) {
//			s2.push(l2->val);
//			l2 = l2->next;
//		}
//		while(!s1.empty() || !s2.empty()){
//			int val1 = s1.empty() ? 0 : s1.top();
//			int val2 = s2.empty() ? 0 : s2.top();
//			int tmpSum = val1 + val2 + carry;
//			carry = tmpSum / 10;
//			
//			//头插法
//			ListNode *node = new ListNode(tmpSum%10);
//			node->next = sum.next;
//			sum.next = node;		
//			if (!s1.empty()) {
//				s1.pop();
//			}
//			if (!s2.empty()) {
//				
//				s2.pop();
//			}
//		}
//		if (carry) {
//			ListNode *node = new ListNode(1);
//			node->next = sum.next;
//			sum.next = node;
//		}
//		return sum.next;
//	}
//};
//真正使用算法
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode sum(-1), *tmp1 = l1, *tmp2 = l2, *last = &sum, *beforeNine = &sum;//指向连续9的上一位
		int len1 = 0, len2 = 0, diff = 0;
		
		//计算两个链表长短
		while (tmp1) {
			len1++;
			tmp1 = tmp1->next;
		}
		while (tmp2) {
			len2++;
			tmp2 = tmp2->next;
		}
		
		//将长链表定为l1,短定位l2,比较方便后续计算		
		if(len2 > len1){
			ListNode *tmp = l1;
			l1 = l2;
			l2 = tmp;
			diff = len2 - len1;
		}else {
			diff = len1 - len2;
		}
		//将超出部分拷贝到新链表中,last代表新链表最后一位,before永远都不在9上面
		while(diff--){
			last->next = new ListNode(l1->val);
			last = last->next;
			if (l1->val != 9) {//因为拷贝过程中不可能有进位,所以只要移动即可,不用置0
				beforeNine = last;
			}
			l1 = l1->next;
		}
		
		//开始遍历链表
		int carry = 0;//向前的进位
		while(l1){
			int tmpSum = l1->val + l2->val;
			last->next = new ListNode(tmpSum%10);
			carry = tmpSum / 10;
			last = last->next;
			if (tmpSum != 9) {//等于9的话,before指针不动,不等于9时指针移动
				if(!carry){//没有进位,则前面所有9都不用置0
					beforeNine = last;
				}else if (beforeNine->val == -1) {//beforeNine是首节点,则增加一个节点1
					//最前端加入1
					ListNode *addFirst = new ListNode(1);
					addFirst->next = sum.next;
					sum.next = addFirst;
					
					//指向第一个9,开始置0
					beforeNine = addFirst->next;
					while(beforeNine != last){
						beforeNine->val = 0;
						beforeNine = beforeNine->next;
					}
				}else {
					beforeNine->val ++;//当前位++
					
					//指向第一个9,开始置0
					beforeNine = beforeNine->next;
					while(beforeNine != last){
						beforeNine->val = 0;
						beforeNine = beforeNine->next;
					}
				}
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		return sum.next;
	}
};
int main(int argc, char *argv[]) {
	ListNode l1(9), l2(9);
	ListNode *p1 = &l1, *p2 = &l2;
	Solution s;
	
	p1->next = new ListNode(8);
	p1 = p1->next;
	p1->next = new ListNode(2);
//	p1 = p1->next;
//	p1->next = new ListNode(3);
	
	p1 = &l1;
		
	p2->next = new ListNode(1);
	p2 = p2->next;
	p2->next = new ListNode(5);
	p2 = &l2;
		
	ListNode *p = s.addTwoNumbers(p1, p2);
	while(p){
		cout << p->val;
		p = p->next;
	}
	
	return 0;
}
/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

我的思路:两个链表相加,高位在前,低位在后,只能从前往后遍历
两种方式:	1.使用栈来存储链表中的数,则可以从低位向高位加
		2.先遍历一遍链表,取得两链表的长度,l1和l2,然后根据|l1-l2|的值先将长链表中的值搬到新链表中,同时维护一个指针p,用来当前位置上,前一组连续出现的9的上一个位置,以防低位有进位
*/