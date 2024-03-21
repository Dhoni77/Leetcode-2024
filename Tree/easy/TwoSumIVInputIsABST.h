//
// Created by Aldrin on 21-03-2024.
//

#ifndef DOOCS_TWOSUMIVINPUTISABST_H
#define DOOCS_TWOSUMIVINPUTISABST_H
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

class TwoSumIVInputIsABST {
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;

        if(st.count(k - root->val)) {
            return true;
        }
        st.insert(root->val);

        bool left = findTarget(root->left, k);
        bool right = findTarget(root->right, k);

        return left or right;
    }
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *  void inorder(TreeNode* root, vector<int> &in){
        if(root == NULL){
            return;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        inorder(root,inorderVal);
        int i=0, j=inorderVal.size()-1;
        while(i<j){
         int sum = inorderVal[i] + inorderVal[j];
         if(sum == k){
            return true;
         }
         else if( sum > k){
            j--;
         }
         else{
            i++;
         }
         }
         return false;
    }
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *     bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q{{root}};
        unordered_set<int> vis;
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                TreeNode* node = q.front();
                q.pop();
                if (vis.count(k - node->val)) {
                    return true;
                }
                vis.insert(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return false;
    }
     */
};


#endif //DOOCS_TWOSUMIVINPUTISABST_H
