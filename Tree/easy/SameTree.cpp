//
// Created by Aldrin on 26-02-2024.
//

#include "SameTree.h"

int main() {
    SameTree st;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
//    root1->right = new TreeNode(3);

    cout << st.isSameTree(root, root1);
}