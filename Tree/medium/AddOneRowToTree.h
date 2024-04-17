//
// Created by Aldrin on 16-04-2024.
//

#ifndef DOOCS_ADDONEROWTOTREE_H
#define DOOCS_ADDONEROWTOTREE_H
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

class AddOneRowToTree {
public:
    // TC: O(N)
    // SC: O(N)
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;

        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        while (!q.empty()) {
            int size = q.size();
            if(d == depth)
                break;
            for(int i=0;i<size;i++) {
                auto node = q.front();
                q.pop();
                if(d == depth - 1) {
                    auto lnode = node->left;
                    auto rnode = node->right;
                    TreeNode* first = new TreeNode(val);
                    first->left = lnode;
                    TreeNode* second = new TreeNode(val);
                    second->right = rnode;
                    node->left = first;
                    node->right = second;
                }
                else {
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
            }
            d++;
        }

        return root;
    }
    //------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:

    void addNode(TreeNode *root, int val, int depth, int curDep) {
        if (root == NULL) {
            return ;
        }

        if (curDep + 1 == depth) {
            TreeNode *ltemp = root->left;
            TreeNode *rtemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            if (ltemp) {
                root->left->left = ltemp;
            }

            if (rtemp) {
                root->right->right = rtemp;
            }
            return;
        }

        addNode(root->left, val, depth, curDep+1);
        addNode(root->right, val, depth, curDep+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == NULL) {
            if (depth == 1) {
                return new TreeNode(val);
            }

            return NULL;
        }

        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int curDepth = 1;
        addNode(root, val, depth, curDepth);
        return root;
    }
};
     */
};


#endif //DOOCS_ADDONEROWTOTREE_H
