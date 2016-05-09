/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head != null) {
            ListNode tHead = new ListNode(head.val);
            ListNode tTail = tHead;
            ListNode node = head.next;
            while (node != null) {
                if (!isDuplicate(tHead, node.val)) {
                    tTail.next = new ListNode(node.val);
                    tTail = tTail.next;
                }
                node = node.next;
            }
            head = tHead;
        }
        return head;
    }
    
    boolean isDuplicate(ListNode head, int val) {
        if (head == null) {
            return false;
        } else {
            ListNode node = head;
            while (node != null) {
                if (node.val == val) {
                    return true;
                }
                node = node.next;
            }
            return false;
        }
    }
}