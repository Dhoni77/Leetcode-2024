//
// Created by Aldrin on 14-03-2024.
//

#ifndef DOOCS_BALANCEDBINARYTREE_H
#define DOOCS_BALANCEDBINARYTREE_H
#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BalancedBinaryTree {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return 1;

        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 and isBalanced(root->left) and isBalanced(root->right);
    }
};


#endif //DOOCS_BALANCEDBINARYTREE_H
