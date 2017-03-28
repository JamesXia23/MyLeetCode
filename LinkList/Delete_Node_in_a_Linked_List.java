class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

public class Delete_Node_in_a_Linked_List {
	public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
	public static void main(String[] args) {
		System.out.println("hello, world");
	}
}
/*
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
the linked list should become 1 -> 2 -> 4 after calling your function.

思路：因为要删除的节点不是最后一个节点，所以只需要将下一个节点的值赋给当前节点，然后删除下一个节点即可
*/