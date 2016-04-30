package leetcode;

import java.util.LinkedList;

public class RemoveDuplicatesFromSortedList {
	public class ListNode {
		   int val;
	       ListNode next;
	       ListNode(int x) { val = x; }
	}
	public static ListNode deleteDuplicates(ListNode head) {
        if(head == null) {
            return null;
        }
        ListNode node = head;
        while(node.next != null) {
            if(node.val == node.next.val){
            	node.next = node.next.next;
            }
            else{
            	node = node.next;
            }
        }
		return head;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedList<ListNode> node = new LinkedList<ListNode>();
				
		
		
	}

}
