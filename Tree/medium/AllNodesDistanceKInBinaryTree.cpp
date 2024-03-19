//
// Created by Aldrin on 18-03-2024.
//

#include "AllNodesDistanceKInBinaryTree.h"

int main() {
    AllNodesDistanceKInBinaryTree allNodesDistanceKInBinaryTree;
    TreeNode* target = nullptr;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    target = root->left;
    allNodesDistanceKInBinaryTree.distanceK(root, target, 2);
}