//
// Created by Aldrin on 20-03-2024.
//

#ifndef DOOCS_CONSTRUCTBINARYSEARCHTREEFROMPREORDER_H
#define DOOCS_CONSTRUCTBINARYSEARCHTREEFROMPREORDER_H
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

class ConstructBinarySearchTreeFromPreorder {
public:
    TreeNode* convert(vector<int>&preorder,int &i,int upperrange){
        if(i==preorder.size() || preorder[i]>upperrange){
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[i++]);
        root->left= convert(preorder,i,root->val);
        root->right=convert(preorder,i,upperrange);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return convert(preorder,i,INT_MAX);
    }
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            TreeNode* curr = root;
            int value = preorder[i];
            while(true){
                if(value < curr->val){
                    if(curr->left == NULL){
                        curr->left = new TreeNode(value);
                        break;
                    }
                    else curr = curr->left;
                }
                else{
                    if(curr->right == NULL){
                        curr->right = new TreeNode(value);
                        break;
                    }
                    else curr = curr->right;
                }
            }
        }
        return root;
    }
     */
};


#endif //DOOCS_CONSTRUCTBINARYSEARCHTREEFROMPREORDER_H
