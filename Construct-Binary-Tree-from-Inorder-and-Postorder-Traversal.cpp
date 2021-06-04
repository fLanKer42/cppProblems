#include <iostream>
#include <bits/stdc++.h>

/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
*/

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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder) {
        int val = postorder[postorder.size() - 1];
        int i = 0;
        while (inorder[i] != val) {
            i++;
        }
        //vector<int> right_i,right_p,left_i,left_p;
        if (postorder.size() == 1) {
            return new TreeNode(val);
        }
        if (i == 0) {
            vector<int> right_i(inorder.begin()+i+1,inorder.end());
            vector<int> right_p(postorder.begin()+i,postorder.end()-1);
            return new TreeNode(val,NULL,build(right_i,right_p));
        }
        if (i == postorder.size() - 1) {
            vector<int> left_i(inorder.begin(),inorder.begin()+i);
            vector<int> left_p(postorder.begin(),postorder.begin()+i);
            return new TreeNode(val,build(left_i,left_p),NULL);
        }
        
        vector<int> left_i(inorder.begin(),inorder.begin()+i);
        vector<int> right_i(inorder.begin()+i+1,inorder.end());
        vector<int> left_p(postorder.begin(),postorder.begin()+i);
        vector<int> right_p(postorder.begin()+i,postorder.end()-1);
        
        /*ret->left = build(left_i,left_p);
        ret->right = build(right_i,right_p);
        */
        return new TreeNode(val,build(left_i,left_p),build(right_i,right_p));
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* ret;
        ret = build(inorder, postorder);
        return ret;
    }
};