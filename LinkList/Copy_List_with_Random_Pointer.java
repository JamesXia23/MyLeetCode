public class Copy_List_with_Random_Pointer {
	public static RandomListNode copyRandomList(RandomListNode head) {
	if (head == null) {
			return null;
		}
	RandomListNode p = head;
	while (p != null) {
		RandomListNode temp = new RandomListNode(p.label);
		temp.next = p.next;
		p.next = temp;
		p = p.next.next;
		}
	p = head;
	while(p != null) {
		if (p.random != null) {
			p.next.random = p.random.next;				
			}
		p = p.next.next;
	}
	p = head;
	RandomListNode copyHead = p.next, q = copyHead;
	
	while(p != null){
		p.next = p.next.next;
		p = p.next;
		if (q.next != null) {
			q.next = q.next.next;
			}
		q = q.next;
	}
	return copyHead;
    }
	public static void main(String[] args) {
		RandomListNode head = new RandomListNode(1);
		head.next = new RandomListNode(2);
		head.next.next = new RandomListNode(3);
		head.next.next.next = new RandomListNode(4);
		head.next.next.next.next = null;
		RandomListNode copyHead = copyRandomList(head);
		while (copyHead != null) {
			System.out.print(copyHead.label + " ");
			copyHead = copyHead.next;
		}
	}
}

/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 * 题意：一个链表节点除了有一个指向下一个节点的指针外，还有一个指向任意节点的指针，要求复制这个链表
 * 思路：比如链表1->2->3->4->null
 * 		遍历链表，产生每遍历一次链表，就产生一个链表节点的拷贝节点，放在源节点之后，如：1->1'->2->2'->3->3'->4->4'->null
 * 		然后再遍历一次链表，将1'的random指针指向1的random指针的下一位，比如1->4,则1’->4',则完成了链表的拷贝，然后将链表分流成两个即可。
 */
