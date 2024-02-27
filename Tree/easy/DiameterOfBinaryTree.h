//
// Created by Aldrin on 27-02-2024.
//

#ifndef DOOCS_DIAMETEROFBINARYTREE_H
#define DOOCS_DIAMETEROFBINARYTREE_H
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

class DiameterOfBinaryTree {
public:
    int maxDiameter = 0;

    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
};


#endif //DOOCS_DIAMETEROFBINARYTREE_H
