//
// Created by Aldrin on 27-02-2024.
//

#include "DiameterOfBinaryTree.h"

int main() {
    DiameterOfBinaryTree diameterOfBinaryTree;

    TreeNode* treeNode = new TreeNode(1);
    treeNode->left = new TreeNode(2);
    treeNode->right = new TreeNode(3);
    treeNode->left->left = new TreeNode(4);
    treeNode->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree.diameterOfBinaryTree(treeNode);
}