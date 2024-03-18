//
// Created by Aldrin on 14-03-2024.
//

#include "BalancedBinaryTree.h"

int main() {
    BalancedBinaryTree balancedBinaryTree;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << balancedBinaryTree.isBalanced(root);
}