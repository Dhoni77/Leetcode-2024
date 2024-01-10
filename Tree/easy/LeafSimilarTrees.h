//
// Created by Aldrin on 09-01-2024.
//

#ifndef DOOCS_LEAFSIMILARTREES_H
#define DOOCS_LEAFSIMILARTREES_H
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

class LeafSimilarTrees {
public:
    vector<int> t1, t2;

    void inorder(TreeNode* root, vector<int> &v) {
        if(root == NULL)
            return;
        inorder(root->left, v);
        if(root->right == NULL and root->left == NULL)
            v.push_back(root->val);
        inorder(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL or root2 == NULL)
            return false;
        inorder(root1, t1);
        inorder(root2, t2);
        if(t1.size() != t2.size())
            return false;
        for(int i = 0; i < t1.size();i++) {
            if(t1[i] != t2[i]) {
                return false;
            }
        }
        return true;
    }
};


#endif //DOOCS_LEAFSIMILARTREES_H
