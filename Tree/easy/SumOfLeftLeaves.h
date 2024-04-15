//
// Created by Aldrin on 14-04-2024.
//

#ifndef DOOCS_SUMOFLEFTLEAVES_H
#define DOOCS_SUMOFLEFTLEAVES_H
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

class SumOfLeftLeaves {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int ans = 0;

        if (root->left) {
            if (root->left->left == nullptr && root->left->right == nullptr)
                ans += root->left->val;
            else
                ans += sumOfLeftLeaves(root->left);
        }
        ans += sumOfLeftLeaves(root->right);

        return ans;
    }
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr)
      return 0;

    int ans = 0;
    stack<TreeNode*> stack{{root}};

    while (!stack.empty()) {
      root = stack.top(), stack.pop();
      if (root->left) {
        if (root->left->left == nullptr && root->left->right == nullptr)
          ans += root->left->val;
        else
          stack.push(root->left);
      }
      if (root->right)
        stack.push(root->right);
    }

    return ans;
  }
};
     */
    //------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * int dfs(TreeNode* root, bool isLeft) {
        if(!root) {
            return 0;
        }

        if(!root->left and !root->right) {
            return isLeft ? root->val : 0;
        }

        return dfs(root->left, true) + dfs(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
     */
};


#endif //DOOCS_SUMOFLEFTLEAVES_H
