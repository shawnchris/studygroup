package leetcode;


public class RotateList {
	public class ListNode {
		   int val;
	       ListNode next;
	       ListNode(int x) { val = x; }
	}
	public ListNode rotateRight(ListNode head, int n) {
		if(head == null || head.next == null){
			return head;
		}
		ListNode dummy = new ListNode(0);
		dummy.next = head;
		ListNode fast = dummy;
		ListNode slow = dummy;
		int i =0;
		for(i =0; fast.next != null; i++){
			fast = fast.next;
		}
		for(int j = i - n%i; j>0; j--){
			slow = slow.next;
		}
		fast.next = dummy.next;
		dummy.next = slow.next;
		slow.next = null;
		return dummy.next;
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
