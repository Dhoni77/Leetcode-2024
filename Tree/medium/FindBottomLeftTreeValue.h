//
// Created by Aldrin on 28-02-2024.
//

#ifndef GEEKSFORGEEKS_FINDBOTTOMLEFTTREEVALUE_H
#define GEEKSFORGEEKS_FINDBOTTOMLEFTTREEVALUE_H
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

class FindBottomLeftTreeValue {
public:
    /*
     DFS
     TC: O(N)
     SC: O(H)
     */
     void f(TreeNode* root, int& ans,int& maxlevel,int level)
            {
                if(root==NULL)
                {
                    return;
                }
                if(level>maxlevel)
                {
                    ans=root->val;
                    maxlevel=level;
                }
                f(root->left,ans,maxlevel,level+1);
                f(root->right,ans,maxlevel,level+1);
            }
            int findBottomLeftValue(TreeNode* root) {
                int ans=0;
                int level=0;
                int maxlevel=0;
                if(root->left==NULL && root->right==NULL)
                {
                    return root->val;
                }
                f(root,ans,maxlevel,level);
                return ans;
            }
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *BFS
     *int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode* ,int>>q;
        int ans;
        int maxline=-1;
        q.push({root,0});
        if(root==NULL)return ans;


        while(!q.empty()){
            auto it=q.front();
            q.pop();

            TreeNode* node=it.first;
            int line =it.second;
            if(line>maxline){
                maxline=line;
                ans=node->val;
            }

            if(node->left)q.push({node->left,line+1});
            if(node->right)q.push({node->right,line+1});
        }


        return ans;
    }
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * BFS
     *
     * int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();

            while(sz-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);

                if(q.empty() and node->right == NULL and node->left == NULL)
                    return node->val;
            }
        }

        return 0;
    }
     */
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * BFS
     * class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> queue;
        TreeNode* current = root;
        queue.push(current);

        while (!queue.empty()) {
            current = queue.front();
            queue.pop();
            if (current->right != nullptr) {
                queue.push(current->right);
            }
            if (current->left != nullptr) {
                queue.push(current->left);
            }
        }
        return current->val;
    }
};
     */
};


#endif //GEEKSFORGEEKS_FINDBOTTOMLEFTTREEVALUE_H
