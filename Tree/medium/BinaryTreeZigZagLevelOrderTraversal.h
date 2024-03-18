//
// Created by Aldrin on 14-03-2024.
//

#ifndef DOOCS_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
#define DOOCS_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
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


class BinaryTreeZigZagLevelOrderTraversal {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool rtol = true;

        while(!q.empty()) {
            int size = q.size();
            rtol = !rtol;
            vector<int> lvls;

            while(size-- > 0) {
                    auto node = q.front();
                    q.pop();

                    if(node->left != nullptr) {
                        q.push(node->left);

                    }

                    if(node->right != nullptr) {
                        q.push(node->right);
                    }

                    lvls.push_back(node->val);
            }
            if(rtol)
                reverse(lvls.begin(), lvls.end());
            ans.push_back(lvls);
        }

        return ans;
    }
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(root==NULL) return {};
            vector<vector<int>> res;
            queue<TreeNode*> q;
            q.push(root);
            int level=0;
            while(!q.empty()){
                int size = q.size();
                vector<int> temp(size);
                for(int i=0;i<size;i++){
                    auto node = q.front();
                    q.pop();
                    if(level%2){
                        temp[size-i-1] = node->val;
                    }
                    else{
                        temp[i] = node->val;
                    }
                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);
                }
                res.push_back(temp);
                level++;
            }
            return res;

        }
    };
     */
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * Dequeue
     *
     * class Solution {
         public:
          vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if (root == nullptr)
              return {};

            vector<vector<int>> ans;
            deque<TreeNode*> dq{{root}};
            bool isLeftToRight = true;

            while (!dq.empty()) {
              vector<int> currLevel;
              for (int sz = dq.size(); sz > 0; --sz)
                if (isLeftToRight) {
                  TreeNode* node = dq.front();
                  dq.pop_front();
                  currLevel.push_back(node->val);
                  if (node->left)
                    dq.push_back(node->left);
                  if (node->right)
                    dq.push_back(node->right);
                } else {
                  TreeNode* node = dq.back();
                  dq.pop_back();
                  currLevel.push_back(node->val);
                  if (node->right)
                    dq.push_front(node->right);
                  if (node->left)
                    dq.push_front(node->left);
                }
              ans.push_back(currLevel);
              isLeftToRight = !isLeftToRight;
            }

            return ans;
          }
};
     */
};


#endif //DOOCS_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
