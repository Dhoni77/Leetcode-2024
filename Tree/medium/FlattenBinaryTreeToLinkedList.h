//
// Created by Aldrin on 19-03-2024.
//

#ifndef DOOCS_FLATTENBINARYTREETOLINKEDLIST_H
#define DOOCS_FLATTENBINARYTREETOLINKEDLIST_H
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

class FlattenBinaryTreeToLinkedList {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *left = root->left, *right = root->right;
        // make left node as null
        root->left = NULL;
        // make right node as left
        root->right = left;
        // move the pointer from root until the last right node is reached
        TreeNode* rightMostNode = root;
        while(rightMostNode->right)
            rightMostNode = rightMostNode->right;
        // assign the right most node to the right node
        rightMostNode->right = right;
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * TreeNode * prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=prev;
        prev=root;
    }
     */
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *     void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left != NULL) {
                TreeNode* prev = curr->left;
                while(prev->right) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
     */
};


#endif //DOOCS_FLATTENBINARYTREETOLINKEDLIST_H
