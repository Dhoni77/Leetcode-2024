//
// Created by Aldrin on 18-03-2024.
//

#include "MaximumWidthOfBinaryTree.h"

int main() {
    MaximumWidthOfBinaryTree maximumWidthOfBinaryTree;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(7);

    cout << maximumWidthOfBinaryTree.widthOfBinaryTree(root);
}