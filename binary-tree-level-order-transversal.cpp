#include <iostream>
#include <bits/stdc++.h>
/* 
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
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
    void callFun(queue<TreeNode*>& nodes, vector<vector<int>>& ret) {
        int n = nodes.size();
        vector<int> val;
        TreeNode* temp;
        for (int i = 0; i < n; i++) {
            temp = nodes.front();
            nodes.pop();
            if (temp) {
                nodes.push(temp->left);
                nodes.push(temp->right);
                val.push_back(temp->val);
            }
        }
        if (val.size() != 0) {
           ret.push_back(val); 
        }
        if (nodes.size() != 0) {
            callFun(nodes,ret);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> nodes;
        nodes.push(root);
        callFun(nodes, ret);
        return ret;
    }
};