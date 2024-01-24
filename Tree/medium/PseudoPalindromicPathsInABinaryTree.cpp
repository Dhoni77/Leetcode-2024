//
// Created by Aldrin on 24-01-2024.
//

#include "PseudoPalindromicPathsInABinaryTree.h"

int main() {
    PseudoPalindromicPathsInABinaryTree pp;

    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(3);
    root1->right = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(1);

    cout << pp.pseudoPalindromicPaths(root1);
}