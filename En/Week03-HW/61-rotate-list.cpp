/*
https://leetcode.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k <= 0 || !head || !head->next) {
            return head;
        } else {
            // make it become a cycle
            int length = 1;
            ListNode* pNode = head;
            while (pNode->next) {
                ++length;
                pNode = pNode->next;
            }
            int k2 = 0;
            if (length == k) {
                return head;
            } else if (length > k) {
                k2 = k;
            } else {
                k2 = k % length;
            }
            pNode->next = head;
            pNode = head;
            for (int i = 0; i < length - k2 - 1; i++) {
                pNode = pNode->next;
            }
            head = pNode->next;
            pNode->next = 0;
            return head;
        }
    }
};