#include <iostream>
#include <bits/stdc++.h>

/*Given the head of a linked list, remove the nth node from the end of the list and return its head.
Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *remover = NULL, *temp = head, *bf = NULL;
        while (temp != NULL) {
            if (count == n-1) {
                remover = head;
            }
            else if (count==n) {
                bf = remover;
                remover = remover->next;
            }
            else if(count > n) {
                remover = remover->next;
                bf = bf->next;
            }
            temp = temp->next;
            count++;
        }
        if (remover == NULL) {
            return head;
        }
        else if (bf == NULL) {
            return remover->next;
        }
        else {
            bf->next = remover->next;
            return head;
        }
    }
};