public class Niuke_LinkList1 {
	public static void main(String[] args) {
		ListNode headA = new ListNode(-1), p = headA;
		ListNode headB = new ListNode(-1);
		for(int i = 0; i < 10; i++) {
			p.next = new ListNode(i*2);
			p = p.next;
		}
		p = headB;
		for(int i = 0; i < 10; i++) {
			p.next = new ListNode(i*5);
			p = p.next;
		}
		ListNode pA = headA, pB = headB;
		while(pA != null && pB != null){
			if(pA.val < pB.val)
				pA = pA.next;
			else if(pA.val > pB.val)
				pB = pB.next;
			else{
				System.out.print(pA.val + " ");
				pA = pA.next;
				pB = pB.next;
			}
		}
//		while(headA != null){
//			System.out.print(headA.val);
//			headA = headA.next;
//		}
//		System.out.println();
//		while(headB != null){
//			System.out.print(headB.val);
//			headB = headB.next;
//		}
	}
}
/*
 * 打印两个有序链表的公共部分
 * 思路：如果有任何一个链表为空，返回null即可，
 * 		如果都不为空，从头开始遍历两个链表，
 * 		如果链表A节点<链表B节点，往后移动A，B不动，
 * 		如果链表A节点>链表B节点，往后移动B，A不动
 * 		如果相等，则输出节点，两个链表均移动，直到有一个链表为空，结束
 * */