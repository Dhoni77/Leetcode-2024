//
// Created by Aldrin on 15-04-2024.
//

#include "SumRootToLeafNumbers.h"

int main() {
    SumRootToLeafNumbers sumRootToLeafNumbers;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << sumRootToLeafNumbers.sumNumbers(root);
}