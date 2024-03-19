//
// Created by Aldrin on 19-03-2024.
//

#include "BinaryTreeMaximumPathSum.h"

int main() {
    BinaryTreeMaximumPathSum binaryTreeMaximumPathSum;

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << binaryTreeMaximumPathSum.maxPathSum(root);
}