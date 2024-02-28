//
// Created by Aldrin on 28-02-2024.
//

#include "FindBottomLeftTreeValue.h"

int main() {
    FindBottomLeftTreeValue findBottomLeftTreeValue;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    cout << findBottomLeftTreeValue.findBottomLeftValue(root);
}