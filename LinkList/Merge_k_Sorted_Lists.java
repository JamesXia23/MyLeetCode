public class Merge_k_Sorted_Lists {
	public ListNode mergeKLists(ListNode[] lists) {
		if(lists == null || lists.length < 1)
			return null;
		if(lists.length == 1)
			return lists[0];
        return mergeK(0, lists.length-1, lists);
    }
	public ListNode mergeK(int start, int end, ListNode[] lists) {
		if(start == end)
			return lists[start];
		if(start + 1 == end)
			return mergeTwo(lists[start], lists[end]);
		int mid = (start + end) / 2;
		return mergeTwo(mergeK(start, mid, lists), mergeK(mid+1, end, lists));
	}
	public ListNode mergeTwo(ListNode head1, ListNode head2){
		if(head1 == null)
			return head2;
		if(head2 == null)
			return head1;
		
		ListNode resHead = new ListNode(-1), p = resHead;
		while(head1 != null && head2 != null){
			if(head1.val < head2.val){
				p.next = head1;
				head1 = head1.next;
			}else{
				p.next = head2;
				head2 = head2.next;
			}
			p = p.next;
		}
		if(head1 == null){
			p.next = head2;
		}else{
			p.next = head1;
		}
		return resHead.next;
	}
}
/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * 题意：合并k个有序链表
 * 思路：分治法，将链表数组分为两部分，如果两部分链表数都为1，直接合并
 * 									如果其中一部分为1，一部分为2，合并2的那部分得到一个链表，然后再合并剩余两个
 * 									如果两部分均大于2，则每部分继续分，直到每部分只有1个或2个的情况，使用上面的方式解决即可
 * 过程：定义两个辅助函数：mergeTwo(ListNode head1, ListNode head2)用来合并两个链表，
 * 						mergeK(int start, int end, ListNode[] lists)用来合并lists中从start到end之间的链表
 * 		mergeK递归过程如下：
 * 			如果start == end，直接返回lists[start]，表示只有一个链表，不需合并
 * 			如果start + 1 == end,直接返回mergeTwo(lists[start], lists[end]), 表示只有两个链表需要合并，直接合并返回即可
 * 			上面两种情况都不满足，则说明需要合并的链表个数大于2，
 * 				则将求出mid = (start+end)/2, 
 * 				将链表组分为start-mid，mid+1-end两部分，然后继续递归求出mergeK(start,mid)和mergeK(mid+1,end)两部分的结果，
 * 				最后返回mergeTwo(mergeK(start,mid), mergeK(mid+1,end))即可
 */