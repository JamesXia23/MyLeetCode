public class Odd_Even_Linked_List {
	public ListNode oddEvenList(ListNode head) {
		if(head == null || head.next == null || head.next.next == null)
			return head;
		ListNode evenHead = head.next, oddTail = head, evenTail = evenHead;
		
		while(evenTail != null){
			oddTail.next = evenTail.next;//偶节点的下一个节点肯定为奇节点（或者null）
			//需要保证oddTail不为空，等下才能接上evenHead
			if(oddTail.next != null)
				oddTail = oddTail.next;
			evenTail.next = oddTail.next;//奇节点下一个节点肯定为偶节点（或者null）
			evenTail = evenTail.next;
		}
		oddTail.next = evenHead;
		return head;
	}
}

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

题意：奇偶链表，将一个链表索引号(从1开始)为偶数的部分全部放在奇数部分的后面
思路：将链表分流为奇链表和偶链表，然后奇链表末尾连上偶链表即可。
注意：需要一个变量来存偶链表头，两个变量来保存两个链表尾，其中奇链表尾不能为空，因为等下要连上偶链表头
		而且有规律：	偶链表尾的下一个节点肯定为奇(或者null)，应该加入到奇链表尾
					奇链表尾的下一个节点肯定为偶(或者null)，应该加入到偶链表尾
*/