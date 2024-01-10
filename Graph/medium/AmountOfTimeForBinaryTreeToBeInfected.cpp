//
// Created by Aldrin on 10-01-2024.
//

#include "AmountOfTimeForBinaryTreeToBeInfected.h"

int main() {
    AmountOfTimeForBinaryTreeToBeInfected at;

    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(5);
    t->right = new TreeNode(3);
    t->right->left = new TreeNode(10);
    t->right->right = new TreeNode(6);
    t->left->right = new TreeNode(4);
    t->left->right->left = new TreeNode(9);
    t->left->right->right = new TreeNode(2);

    cout << at.amountOfTime(t, 3);
}