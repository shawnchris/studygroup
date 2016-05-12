/*
https://leetcode.com/problems/linked-list-cycle/

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        } 
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                break;
            }
            if (fast == slow) {
                return true;
            }
        } while (fast != slow);
        return false;
    }
};