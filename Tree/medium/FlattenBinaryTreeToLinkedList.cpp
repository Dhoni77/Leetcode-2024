//
// Created by Aldrin on 19-03-2024.
//

#include "FlattenBinaryTreeToLinkedList.h"

int main() {
    FlattenBinaryTreeToLinkedList flattenBinaryTreeToLinkedList;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flattenBinaryTreeToLinkedList.flatten(root);
}