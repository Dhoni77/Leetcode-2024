//
// Created by Aldrin on 14-03-2024.
//

#include "MaximumDepthOfBinaryTree.h"

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left = new TreeNode(3);
    MaximumDepthOfBinaryTree maximumDepthOfBinaryTree;
    cout << maximumDepthOfBinaryTree.maxDepth(root);
}