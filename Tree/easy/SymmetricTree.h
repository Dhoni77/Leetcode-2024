//
// Created by Aldrin on 18-03-2024.
//

#ifndef DOOCS_SYMMETRICTREE_H
#define DOOCS_SYMMETRICTREE_H
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

class SymmetricTree {
public:
    bool mirror(TreeNode* p, TreeNode* q) {
        if(p == nullptr and q == nullptr)
            return true;

        if(p == nullptr or q == nullptr)
            return false;

        if(p->val != q->val)
            return false;

        return mirror(p->left, q->right) and mirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr and root->right == nullptr)
            return true;
        return mirror(root->left, root->right);
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:
        bool issame(TreeNode* l,TreeNode* r){
            if(l==NULL && r==NULL)return true;
            if(l==NULL || r==NULL)return false;
            return (l->val==r->val)&&issame(l->left,r->right)&&issame(l->right,r->left);
        }
        bool isSymmetric(TreeNode* root) {
            return issame(root->left,root->right);
        }
    };
     */
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            queue< TreeNode* >q;
            q.push(root);
            while(!q.empty()){
                int k=q.size();
                vector<int>a;
                while(k--){
                    TreeNode*t=q.front();
                    q.pop();
                    if(t==NULL){
                        a.push_back(INT_MIN);
                        continue;
                    }
                    else{
                        a.push_back(t->val);
                    }

                    // if(t->left!=NULL){
                    q.push(t->left);

                    // if(t->right!=NULL){
                    q.push(t->right);

                }
                for(int i=0;i<a.size()/2;i++)
                {
                    if(a[i]!=a[a.size()-1-i]){
                        return false;
                    }
                }
            }
            return true;

        }
    };
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root->left);
            q.push(root->right);

            while (!q.empty()) {
                TreeNode* left_node = q.front();
                q.pop();
                TreeNode* right_node = q.front();
                q.pop();

                if (!left_node && !right_node)
                    continue;
                if (!left_node || !right_node)
                    return false;
                if (left_node->val != right_node->val)
                    return false;

                q.push(left_node->left);
                q.push(right_node->right);
                q.push(left_node->right);
                q.push(right_node->left);
            }

            return true;
        }
    };
     */
};


#endif //DOOCS_SYMMETRICTREE_H
