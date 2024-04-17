//
// Created by Aldrin on 17-04-2024.
//

#include "SmallestStringStartingFromLeaf.h"

int main() {
    SmallestStringStartingFromLeaf smallestStringStartingFromLeaf;

    TreeNode* root = new TreeNode(25);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(0);
    root->right->left = new TreeNode(0);

    cout << smallestStringStartingFromLeaf.smallestFromLeaf(root);
}