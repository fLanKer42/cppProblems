#include <iostream>
#include <bits/stdc++.h>
/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int val = preorder[0];
        if (preorder.size() == 1) {
            return new TreeNode(val);
        }
        int i = 0;
        while (inorder[i] != val) {
            i++;
        }
        if (i == 0) {
            vector<int> right_p(preorder.begin()+i+1,preorder.end());
            vector<int> right_i(inorder.begin()+i+1,inorder.end());
            return new TreeNode(val,NULL,buildTree(right_p,right_i));
        }
        if (i == preorder.size() - 1) {
            vector<int> left_p(preorder.begin()+1,preorder.begin()+i+1);
            vector<int> left_i(inorder.begin(), inorder.begin()+i);
            return new TreeNode(val,buildTree(left_p,left_i),NULL);
        }
        vector<int> left_p(preorder.begin()+1,preorder.begin()+i+1);
        vector<int> left_i(inorder.begin(), inorder.begin()+i);
        vector<int> right_p(preorder.begin()+i+1,preorder.end());
        vector<int> right_i(inorder.begin()+i+1,inorder.end());
        return new TreeNode(val,buildTree(left_p,left_i),buildTree(right_p,right_i));
    }
};