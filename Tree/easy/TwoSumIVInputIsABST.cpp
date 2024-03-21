//
// Created by Aldrin on 21-03-2024.
//

#include "TwoSumIVInputIsABST.h"

int main() {
    TwoSumIVInputIsABST twoSumIvInputIsAbst;

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << twoSumIvInputIsAbst.findTarget(root, 28);
}