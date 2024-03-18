//
// Created by Aldrin on 15-03-2024.
//

#include "BinaryTreeRightSideView.h"

int main() {
    BinaryTreeRightSideView binaryTreeRightSideView;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> ans = binaryTreeRightSideView.rightSideView(root);

    for(auto n: ans)
        cout << n << "\t";
    cout << endl;
}