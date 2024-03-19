//
// Created by Aldrin on 19-03-2024.
//

#ifndef GEEKSFORGEEKS_BOUNDARYTRAVERSALOFBINARYTREE_H
#define GEEKSFORGEEKS_BOUNDARYTRAVERSALOFBINARYTREE_H
#include "bits/stdc++.h"
using namespace std;


template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

class BoundaryTraversalOfBinaryTree {
public:
    vector<int> ans, pos;
    void pre(TreeNode<int>* root) {
        if(!root or root->left == nullptr and root->right == nullptr)
            return;

        ans.push_back(root->data);
        if(root->left)
            pre(root->left);
        else
            pre(root->right);
    }

    void inorder(TreeNode<int>* root) {
        if(!root)
            return;

        inorder(root->left);
        if(root->left == nullptr and root->right == nullptr)
            ans.push_back(root->data);
        inorder(root->right);
    }

    void post(TreeNode<int>* root) {
        if(!root or root->left == nullptr and root->right == nullptr)
            return;

        pos.push_back(root->data);
        if(root->right)
            post(root->right);
        else
            post(root->left);
    }

    vector<int> traverseBoundary(TreeNode<int> *root)
    {
        // Write your code here.
        pre(root);
        inorder(root);
        post(root->right);
        reverse(pos.begin(), pos.end());
        for(int n: pos)
            ans.push_back(n);
        return ans;
    }
};


#endif //GEEKSFORGEEKS_BOUNDARYTRAVERSALOFBINARYTREE_H
