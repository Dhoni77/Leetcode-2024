//
// Created by Aldrin on 26-02-2024.
//

#ifndef DOOCS_SAMETREE_H
#define DOOCS_SAMETREE_H
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

class SameTree {
public:
    bool isSame(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL)
            return true;
        if(p == NULL or q == NULL)
            return false;
        if(p->val != q->val)
            return false;
       return isSame(p->left, q->left) and isSame(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p, q);
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *     bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (!p || !q) return false;
        queue<TreeNode*> q1{{p}};
        queue<TreeNode*> q2{{q}};
        while (!q1.empty() && !q2.empty()) {
            p = q1.front();
            q = q2.front();
            if (p->val != q->val) return false;
            q1.pop();
            q2.pop();
            TreeNode *la = p->left, *ra = p->right;
            TreeNode *lb = q->left, *rb = q->right;
            if ((la && !lb) || (lb && !la)) return false;
            if ((ra && !rb) || (rb && !ra)) return false;
            if (la) {
                q1.push(la);
                q2.push(lb);
            }
            if (ra) {
                q1.push(ra);
                q2.push(rb);
            }
        }
        return true;
    }
     */
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * bool isSameTree(TreeNode* p, TreeNode* q) {
         if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;
        else if(p->val != q->val)
            return false;
        else
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
     */
};


#endif //DOOCS_SAMETREE_H
