//
// Created by Aldrin on 11-01-2024.
//

#include "MaximumDifferenceBetweenNodeAndAncestor.h"

int main() {
    MaximumDifferenceBetweenNodeAndAncestor md;

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    vector<int> arr{1, 1, 2, 3};

    cout << md.maxAncestorDiff(root);
}