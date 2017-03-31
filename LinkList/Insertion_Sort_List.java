public class Insertion_Sort_List {
	public ListNode insertionSortList(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}
        ListNode readHead = new ListNode(-1);//辅助空头结点
        readHead.next = head;
        ListNode cur = head;//cur的下一个节点为要调整的节点
        
        while (cur.next != null) {//从第二个节点开始调整
        	ListNode p = readHead;
        	while(p.next.val < cur.next.val){
            	p = p.next;
            }
        	if (!p.next.equals(cur.next)) {//在到cur.next之前已经找到一个大于等于cur.next的节点了，将cur.next插入到这个节点前面
				ListNode temp = cur.next;//保存要调整节点
				cur.next = cur.next.next;//原表中删除,cur的新next就是下一个要调整的数
				temp.next = p.next;//要调整节点挂载第一个大于等于他的数
				p.next = temp;//插入要调整的节点
			}else{//cur.next比前面任何一个节点都大，则无需调整，直接跳到下一轮比较
				cur = cur.next;
			}
		}
        return readHead.next;
    }
}
/**
 * Sort a linked list using insertion sort.
 * 题意：使用插入排序算法来排序链表
 * 思路：数组的插入排序是每次跟前一个数比较，然后再跟前前一个数比较，直到找到一个比他小的数，但是由于链表无法向前跳，
 * 		所以变成在链表中就变为从表头开始，找到第一个大于等于他的数，直接插入在他前面即可
 */
