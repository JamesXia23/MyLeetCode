public class Reorder_List {
	public void reorderList(ListNode head) {
		if (head == null || head.next == null || head.next.next == null) {
			return ;
		}
	ListNode fast = head, slow = head;
	while (fast.next != null && fast.next.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}
	ListNode secondPre = slow;//后半部分链表的上一个节点
	ListNode readTail = slow.next;//最终的尾节点
	ListNode now = readTail.next;//当前需要调整的节点
	while (now != null) {//反转后半部分链表
			readTail.next = now.next;
			now.next = secondPre.next;
			secondPre.next = now;
			
			now = readTail.next;
		}
	ListNode secondHead = secondPre.next;//断开两个链表
	secondPre.next = null;
	
	now = head;
	while (now != null && secondHead != null) {
		ListNode temp = secondHead.next;//保存另一个链表剩下节点
		secondHead.next = now.next;	//插入节点后部挂载插入点后部分链表
		now.next = secondHead;	//插入点前一个节点指向要插入节点
		secondHead = temp;	//更新要插入节点
		
		now = now.next.next;//更新插入点
		}
    }
}
/**
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You must do this in-place without altering the nodes' values.
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 * 题意：按照上面的规律重构链表，要求不使用额外空间
 * 思路：利用快慢指针找到链表中点(对于偶数个节点来说，慢指针最后会指向第n/2-1,下标从0开始)，然后将后半部分链表反转，然后再两个链表交叉插入
 */