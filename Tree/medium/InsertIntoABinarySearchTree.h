//
// Created by Aldrin on 20-03-2024.
//

#ifndef DOOCS_INSERTINTOABINARYSEARCHTREE_H
#define DOOCS_INSERTINTOABINARYSEARCHTREE_H
#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class InsertIntoABinarySearchTree {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root, *prev = nullptr;
        while(node) {
            if(val > node->val) {
                prev = node;
                node = node->right;
                if(!node) {
                    prev->right = new TreeNode(val);
                }
            }
            else {
                prev = node;
                node = node->left;
                if(!node) {
                    prev->left = new TreeNode(val);
                }
            }
        }
        return root;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *     TreeNode*help(TreeNode*root,int val){
        if(root==NULL)
            return new TreeNode(val);
        if(root->val > val)
            root->left=help(root->left,val);
        else
            root->right=help(root->right,val);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     return help(root,val);
    }
     */
};


#endif //DOOCS_INSERTINTOABINARYSEARCHTREE_H
