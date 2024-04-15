//
// Created by Aldrin on 15-04-2024.
//

#ifndef DOOCS_SUMROOTTOLEAFNUMBERS_H
#define DOOCS_SUMROOTTOLEAFNUMBERS_H
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

class SumRootToLeafNumbers {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int path, int& ans) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            ans += path * 10 + root->val;
            return;
        }

        dfs(root->left, path * 10 + root->val, ans);
        dfs(root->right, path * 10 + root->val, ans);
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * int sumNumbers(TreeNode* root,string number="") {
        if(!root)return 0;
        number+=std::to_string(root->val);
        if(!root->left&&!root->right){
            return stoi(number);
        }
        int leftsum=sumNumbers(root->left,number);
        int rightsum=sumNumbers(root->right,number);
        return leftsum+rightsum;
    }
     */
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * int sumNumbers(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int s) -> int {
            if (!root) return 0;
            s = s * 10 + root->val;
            if (!root->left && !root->right) return s;
            return dfs(root->left, s) + dfs(root->right, s);
        };
        return dfs(root, 0);
    }
     */
};


#endif //DOOCS_SUMROOTTOLEAFNUMBERS_H
