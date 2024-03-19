//
// Created by Aldrin on 18-03-2024.
//

#include "CountCompleteTreeNodes.h"

int main() {
    CountCompleteTreeNodes countCompleteTreeNodes;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << countCompleteTreeNodes.countNodes(root);
}