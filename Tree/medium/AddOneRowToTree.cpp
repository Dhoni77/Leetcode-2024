//
// Created by Aldrin on 16-04-2024.
//

#include "AddOneRowToTree.h"

int main() {
    AddOneRowToTree addOneRowToTree;

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(10);
    root->left->left->right = new TreeNode(11);
    root->left->right->left = new TreeNode(12);
    root->left->right->right = new TreeNode(13);
    root->right->left->left = new TreeNode(14);

    addOneRowToTree.addOneRow(root, 1, 3);
}