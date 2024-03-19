//
// Created by Aldrin on 18-03-2024.
//

#ifndef DOOCS_COUNTCOMPLETETREENODES_H
#define DOOCS_COUNTCOMPLETETREENODES_H
#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CountCompleteTreeNodes {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int cnt = 0;
        if(root != nullptr) cnt++;
        cnt += countNodes(root->left);
        cnt += countNodes(root->right);
        return cnt;
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * int count = 0;

    void dfs(TreeNode* root) {
        if(root == NULL)
            return;

        count++;
        dfs(root->left);
        dfs(root->right);
    }

    int countNodes(TreeNode* root) {
        dfs(root);
        return count;
    }
     */
};


#endif //DOOCS_COUNTCOMPLETETREENODES_H
