//
// Created by Aldrin on 15-03-2024.
//

#ifndef DOOCS_BINARYTREERIGHTSIDEVIEW_H
#define DOOCS_BINARYTREERIGHTSIDEVIEW_H
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

class BinaryTreeRightSideView {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            vector<int> lvl;
            while(size--) {
                auto node = q.front();
                lvl.push_back(node->val);
                q.pop();
                if(root->left != nullptr)
                    q.push(root->left);
                if(root->right != nullptr)
                    q.push(root->right);
            }
            result.push_back(lvl.back());
        }
        return result;
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
    class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            if(!root) return {};
            vector<int> ans;
            queue<pair<TreeNode*,int>> q;
            q.push({root,1});
            while(!q.empty()) {
                auto curr = q.front();
                TreeNode* currNode = curr.first;
                int level = curr.second;
                q.pop();
                if(currNode->left) q.push({currNode->left, level+1});
                if(currNode->right) q.push({currNode->right, level+1});
                if(q.empty() || level != q.front().second) ans.push_back(currNode->val);
            }
            return ans;
        }
    };
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:
        void rightview(TreeNode* root,vector<int>&vec,int level){
            if(root==NULL){
                return ;
            }
            if(level==vec.size()){
                vec.push_back(root->val);
            }
            rightview(root->right,vec,level+1);
            rightview(root->left,vec,level+1);
        }
        vector<int> rightSideView(TreeNode* root) {
            vector<int> v;
            rightview(root,v,0);
            return v;
        }
    };
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * 
    class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            queue<TreeNode*> q;
            vector<int> values;
            if (root) q.push(root);

            while (!q.empty()){
                int numberOfNodes = q.size();
                values.push_back(q.back()->val);

                for (int i = 0; i < numberOfNodes; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            return values;
        }
    };
     */
};


#endif //DOOCS_BINARYTREERIGHTSIDEVIEW_H
