package leetcode;

public class SwapNodesInPairs {
	public class ListNode {
		   int val;
	       ListNode next;
	       ListNode(int x) { val = x; }
	}
	 public ListNode swapPairs(ListNode head) {
	        ListNode dummy = new ListNode(0);
	        dummy.next = head;
	        head = dummy;
	        while (head.next != null && head.next.next != null){
	        	ListNode n1 = head.next;
	        	ListNode n2 = head.next.next;
	        	head.next = n2;
	        	n1.next = n2.next;
	        	n2.next = n1;
	        	
	        	head = n1;
	        }
	        return dummy.next;
	 }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
	}

}
