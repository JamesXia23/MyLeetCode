public class Intersection_of_Two_Linked_Lists {
	public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
	int lenA = 0, lenB = 0;
	ListNode pA = headA, pB = headB;
	while(pA != null){
		lenA++;
		pA = pA.next;
	}
	while(pB != null){
		lenB++;
		pB = pB.next;
	}
	int diff = lenA - lenB;
	pA = headA;
	pB = headB;
	if(diff >= 0){
		while(diff-- > 0){
			pA = pA.next;
		}
	}else{
		diff = -diff;
		while(diff-- > 0){
			pB = pB.next;
		}
	}
	while(pA != null){
		if(pA.equals(pB)){
			return pA;
		}
		pA = pA.next;
		pB = pB.next;
	}
	return null;
    }
	public static void main(String[] args) {
		ListNode head1 = new ListNode(1);
		head1.next = new ListNode(2);
		ListNode head2 = new ListNode(2);
		head2.next = new ListNode(3);
		head2.next.next = head1.next;
		head1.next.next = new ListNode(4);
		head1.next.next.next = new ListNode(5);
		
		ListNode res = getIntersectionNode(head1, head2);
		System.out.println(res.val);
//		while(head1 != null){
//			System.out.print(head1.val);
//			head1 = head1.next;
//		}
//		System.out.println();
//		while(head2 != null){
//			System.out.print(head2.val);
//			head2 = head2.next;
//		}
		
	}
}

/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:

A:          a1 → a2
		   ↘
		     c1 → c2 → c3
		   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

题意：找到两个链表的交叉点，如果没有交叉点，则返回null
思路：先遍历两个链表，得到长度之差d，然后长链表先走d步，然后两个链表一齐走，记录第一个相同的节点，
												如果从第一个节点开始往后一直相同，则交叉，
												如果出现一个不同，就重新寻找下一个相同的点
 */
