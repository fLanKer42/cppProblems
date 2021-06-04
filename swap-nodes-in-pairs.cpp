#include <iostream>
#include <bits/stdc++.h>

/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swaps(ListNode* h, ListNode* n) {
        if (n) {
            if (n->next) {
                h->next = swaps(n->next, n->next->next);
            }
            else {
                h->next = NULL;
            }
            n->next = h;
            return n;
        }
        else {
            return h;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if (head) {
            head = swaps(head, head->next);
        }
        return head;
    }
};