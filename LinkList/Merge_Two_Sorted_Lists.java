class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode readHead = new ListNode(-1);
		ListNode p = readHead;
		while (l1 != null && l2 != null) {
			if (l1.val < l2.val) {
				p.next = l1;
				l1 = l1.next;
			}else {
				p.next = l2;
				l2 = l2.next;
			}
			p = p.next;
		}
		p.next = (l1 == null)? l2 : l1;
		return readHead.next;
	}
	public static void main(String[] args) {
		System.out.println("hello world");
	}
}
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

/*
合并两个有序链表
*/