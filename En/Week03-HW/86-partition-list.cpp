/*
https://leetcode.com/problems/partition-list/

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if (head && head->next) {
            // create two lists: one for less numbers, the other for greater numbers
            ListNode* lessHead    = 0;
            ListNode* greaterHead = 0;
            ListNode* lessNode    = 0;
            ListNode* greaterNode = 0;
            ListNode* pNode = head;
            while (pNode) {
                if (pNode->val < x) {
                    if (!lessHead) {
                        lessHead = new ListNode(pNode->val);
                        lessNode = lessHead;
                    } else {
                        lessNode->next = new ListNode(pNode->val);
                        lessNode = lessNode->next;
                    }
                } else {
                    if (!greaterHead) {
                        greaterHead = new ListNode(pNode->val);
                        greaterNode = greaterHead;
                    } else {
                        greaterNode->next = new ListNode(pNode->val);
                        greaterNode = greaterNode->next;
                    }
                }
                pNode = pNode->next;
            }
            if (!lessHead) {
                head = greaterHead;
            } else if (!greaterHead) {
                head = lessHead;
            } else {
                head = lessHead;
                lessNode = lessHead;
                while (lessNode->next) {
                    lessNode = lessNode->next;
                }
                lessNode->next = greaterHead;
            }
        }
        return head;
    }
};