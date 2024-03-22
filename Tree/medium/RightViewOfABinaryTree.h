//
// Created by Aldrin on 11-07-2022.
//

#ifndef DOOCS_RIGHTVIEWOFABINARYTREE_H
#define DOOCS_RIGHTVIEWOFABINARYTREE_H

class TreeNode{
    int val;

};

class RightViewOfABinaryTree {
/*
 *  vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;

        if(!root)
            return {};

        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                int data = node->val;
                if(i == sz - 1)
                    ans.push_back(data);

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
 */
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int depth, vector<int>& ans) {
    if (!root)
      return;

    if (depth == ans.size())
      ans.push_back(root->val);
    dfs(root->right, depth + 1, ans);
    dfs(root->left, depth + 1, ans);
  }
};
    TC: O(n)
    SC: O(h)
 */
};


#endif //DOOCS_RIGHTVIEWOFABINARYTREE_H
