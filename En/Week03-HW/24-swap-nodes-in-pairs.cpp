/*
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmpHead = new ListNode(0);;
        tmpHead->next = head;
        ListNode* pNode = tmpHead;
        
        while(pNode->next && pNode->next->next ) {
            swapOnePair(pNode);
            pNode = pNode->next->next;
        }
        head = tmpHead->next;
        return head;
    }
    
    void swapOnePair(ListNode* &pairHead) {
        ListNode* lNode = pairHead->next;
        ListNode* rNode = pairHead->next->next;
        pairHead->next = rNode;
        lNode->next = rNode->next;
        rNode->next = lNode;
    }
};