#include <iostream>
#include <bits/stdc++.h>

/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void con(Node* left, Node* right) {
        if (left == NULL) {
            return;
        }
        left->next = right;
        right->next = NULL;
        con(left->left, left->right);
        con(left->right,right->left);
        con(right->left, right->right);
        return;
    }
    Node* connect(Node* root) {
        if (root==NULL) {
            return NULL;
        }
        root->next = NULL;
        con(root->left,root->right);
        return root;
    }
};