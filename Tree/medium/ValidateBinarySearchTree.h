//
// Created by Aldrin on 11-08-2022.
//

#ifndef DOOCS_VALIDATEBINARYSEARCHTREE_H
#define DOOCS_VALIDATEBINARYSEARCHTREE_H

//https://leetcode.com/problems/validate-binary-search-tree/

class ValidateBinarySearchTree {
/*
 *  bool isValidBST(TreeNode* root) {
        return f(root, NULL, NULL);
    }

    bool f(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(!root)
            return true;

        if(minNode and root->val <= minNode->val)
            return false;

        if(maxNode and root->val >= maxNode->val)
            return false;

        return f(root->left, minNode, root) and f(root->right, root, maxNode);
    }
 */
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stack;
    TreeNode* pred = nullptr;

    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top(), stack.pop();
      if (pred && pred->val >= root->val)
        return false;
      pred = root;
      root = root->right;
    }

    return true;
  }
};

 */
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        inOrder(root);
        for (int i=1; i<tree.size(); i++)
            if (tree[i] <= tree[i-1])
                return false;
        return true;
    }
 */
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 *  bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return helper(root, prev);
    }
    bool helper(TreeNode* curr, TreeNode* &prev) {
        if (!curr)
            return true;
        if (!helper(curr->left, prev))
            return false;
        if (prev != NULL && prev->val >= curr->val)
            return false;
        prev = curr;
        if (!helper(curr->right, prev))
            return false;
        return true;
    }
 */
};


#endif //DOOCS_VALIDATEBINARYSEARCHTREE_H
