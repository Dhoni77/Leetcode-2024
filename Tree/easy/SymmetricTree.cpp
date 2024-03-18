//
// Created by Aldrin on 18-03-2024.
//

#include "SymmetricTree.h"

int main() {
    SymmetricTree symmetricTree;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << symmetricTree.isSymmetric(root);
}