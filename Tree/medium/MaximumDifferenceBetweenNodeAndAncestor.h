//
// Created by Aldrin on 11-01-2024.
//

#ifndef DOOCS_MAXIMUMDIFFERENCEBETWEENNODEANDANCESTOR_H
#define DOOCS_MAXIMUMDIFFERENCEBETWEENNODEANDANCESTOR_H
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

class MaximumDifferenceBetweenNodeAndAncestor {
public:
    int maxAncestorDiff(TreeNode* root) {
        return getMaxDiff(root, INT_MIN, INT_MAX);
    }

    int getMaxDiff(TreeNode* root, int maxVal, int minVal) {
        if(root == NULL)
            return 0;
        int maxi = max(maxVal, root->val);
        int mini = min(minVal, root->val);
        int left = getMaxDiff(root->left, maxi, mini);
        int right = getMaxDiff(root->right, maxi, mini);
        return max({maxi-mini, left, right});
    }
};


#endif //DOOCS_MAXIMUMDIFFERENCEBETWEENNODEANDANCESTOR_H
