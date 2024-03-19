//
// Created by Aldrin on 19-03-2024.
//

#include "VerticalOrderTraversalOfABinaryTree.h"

int main() {
    VerticalOrderTraversalOfABinaryTree verticalOrderTraversalOfABinaryTree;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    verticalOrderTraversalOfABinaryTree.verticalTraversal(root);
}