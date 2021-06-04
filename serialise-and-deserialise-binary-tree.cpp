/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
*/



#include <iostream>
#include <bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        TreeNode* temp;
        queue<TreeNode*> q;
        if (!root) {
            s.push_back(']');
            return s;
        }
        q.push(root);
        while (!q.empty()) {
            temp = q.front();
            if (!temp) {
                s.push_back('n');
                s.push_back(',');
            }
            else {
                s.append(to_string(temp->val));
                q.push(temp->left);
                q.push(temp->right);
                s.push_back(',');
                if (!temp->left) {
                    if (!temp->right) {
                        s.push_back('#');
                    }
                    else {
                        s.push_back('%');
                    }
                }
                else if(!temp->right) {
                    s.push_back('!');
                }
                
            }
            q.pop();
        }
        s.push_back(']');
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[0] == ']') {
            return NULL;
        }
        TreeNode* ret = (TreeNode*)malloc(sizeof(TreeNode));
        queue<TreeNode*> q;
        q.push(ret);
        string curr ="";
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                if (curr[0] == 'n') {
                    q.pop();
                }
                else {
                    q.front()->val = stoi(curr);
                    if (data[i+1] == '#') {
                        q.front()->right = NULL;
                        q.front()->left = NULL;
                        q.push(q.front()->left);
                        q.push(q.front()->right);
                        i++;
                    }
                    else if (data[i+1] == '%') {
                        q.front()->right = new TreeNode(5);
                        q.front()->left = NULL;
                        q.push(q.front()->left);
                        q.push(q.front()->right);
                        i++;
                    }
                    else if (data[i+1] == '!') {
                        q.front()->left = new TreeNode(10);
                        q.front()->right = NULL;
                        q.push(q.front()->left);
                        q.push(q.front()->right);
                        i++;
                    }
                    else {
                        q.front()->left = new TreeNode(10);
                        q.front()->right = new TreeNode(5);
                        q.push(q.front()->left);
                        q.push(q.front()->right);
                    }
                    q.pop();
                }
                curr = "";
            }
            else {
                curr.push_back(data[i]);
            }
        }

        return ret;
    }
};
