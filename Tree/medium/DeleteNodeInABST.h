//
// Created by Aldrin on 22-03-2024.
//

#ifndef DOOCS_DELETENODEINABST_H
#define DOOCS_DELETENODEINABST_H
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

class DeleteNodeInABST {
public:
    TreeNode* findLastRight(TreeNode* root) {
        if(root->right == nullptr)
            return root;
        return findLastRight(root->right);
    }

    TreeNode* helper(TreeNode* root) {
        if(root->left == nullptr)
            return root->right;
        if(root->right == nullptr)
            return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;
        if(root->val == key)
            return helper(root);
        TreeNode* dummy = root;
        while(root != nullptr) {
            if(root->val > key) {
                if(root->left != nullptr and root->left->val == key) {
                    root->left = helper(root->left);
                }
                else {
                    root = root->left;
                }
            }
            else {
                if(root->right != nullptr and root->right->val == key) {
                    root->right = helper(root->right);
                }
                else root = root->right;
            }
        }
        return dummy;
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * TreeNode *deleteNode(TreeNode *root, int key) {
    if (root) {
      if (key < root->val)
        root->left = deleteNode(root->left, key);
      else if (key > root->val)
        root->right = deleteNode(root->right, key);
      else {
        if (!root->left && !root->right) return NULL;
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode *temp = root->left;
        while (temp->right) temp = temp->right;
        temp->right = root->right;
        return root->left;
      }
    }
    return root;
  }
     */
};


#endif //DOOCS_DELETENODEINABST_H
