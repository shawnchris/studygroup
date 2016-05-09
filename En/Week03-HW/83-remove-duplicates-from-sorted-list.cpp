/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head) {
            ListNode* pHead = new ListNode(head->val);
            ListNode* pTail = pHead;
            
            ListNode* pNode = head->next;
            while (pNode != NULL) {
                if (isDuplicate(pHead, pNode->val)) {
                    
                } else {
                    pTail->next = new ListNode(pNode->val);
                    pTail = pTail->next;
                }
                pNode = pNode->next;
            }
            head = pHead;
        }
        return head;
    }
    
    bool isDuplicate(ListNode* head, int val) {
        ListNode* pNode = head;
        while(pNode) {
            if (pNode->val == val) {
                return true;
            }
            pNode = pNode->next;
        }
        return false;
    }
};