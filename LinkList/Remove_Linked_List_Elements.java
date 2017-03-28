class Solution {
	public ListNode removeElements(ListNode head, int val) {
		ListNode readHead = new ListNode(-1);
		ListNode p = readHead;
		readHead.next = head;
		
		while (p.next != null) {
			if (p.next.val == val) {
				p.next = p.next.next;
			}else {
				p = p.next;
			}
		}
		return readHead.next;
	}
}
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

题意:给定一个数,删除链表中所有等于这个数的节点
*/