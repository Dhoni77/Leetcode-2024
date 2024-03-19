//
// Created by Aldrin on 19-03-2024.
//

#include "BoundaryTraversalOfBinaryTree.h"

int main() {
    BoundaryTraversalOfBinaryTree boundaryTraversalOfBinaryTree;

    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(20);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(8);
    root->left->right->left = new TreeNode<int>(7);
    root->right->left = new TreeNode<int>(18);
    root->right->right = new TreeNode<int>(25);

    boundaryTraversalOfBinaryTree.traverseBoundary(root);
}