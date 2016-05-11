/*
https://leetcode.com/problems/odd-even-linked-list/

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode*  oddNode = new ListNode(0);
        ListNode*  oddHead = oddNode;
        ListNode* evenNode = new ListNode(0);
        ListNode* evenHead = evenNode;
        ListNode* curr = head;
        int i = 1;
        while (curr) {
            // Please note here we are talking about the node number and not the value in the nodes.
            if (i % 2 == 1) {
                oddNode->next = curr;
                oddNode = oddNode->next;
            } else {
                evenNode->next = curr;
                evenNode = evenNode->next;
            }
            curr = curr->next;
            ++i;
        }
        evenNode->next = 0;
        oddNode->next = evenHead->next;
        return oddHead->next;
    }
};