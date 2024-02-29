//
// Created by Aldrin on 29-02-2024.
//

#include "EvenOddTree.h"

int main() {
    EvenOddTree evenOddTree;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(2);

    cout << evenOddTree.isEvenOddTree(root);
}