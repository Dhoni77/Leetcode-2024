//
// Created by Aldrin on 29-02-2024.
//

#ifndef DOOCS_EVENODDTREE_H
#define DOOCS_EVENODDTREE_H
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

class EvenOddTree {
public:
    bool isEvenOddTre(TreeNode* root) {
        queue<TreeNode*> q;
        bool toggleLvl = false;
        q.push(root);

        while (!q.empty()) {
            toggleLvl = !toggleLvl;
            int sz = (int) q.size(), prev = toggleLvl ? 0 : INT_MAX;

            while(sz-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                if(toggleLvl) {
                    // even level
                    if((node->val & 1) and (prev < node->val)) {
                        prev = node->val;
                    }
                    else return false;
                }
                else {
                    // odd level
                    if(node->val % 2 == 0 and (prev > node->val)) {
                        prev = node->val;
                    }
                    else return false;
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }

        return true;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * BFS
     *
     * bool isEvenOddTree(TreeNode* root) {
        int even = 1;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int prev = even ? 0 : 1e6;
            for (int n = q.size(); n; --n) {
                root = q.front();
                q.pop();
                if (even && (root->val % 2 == 0 || prev >= root->val)) return false;
                if (!even && (root->val % 2 == 1 || prev <= root->val)) return false;
                prev = root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            even ^= 1;
        }
        return true;
    }
     */
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * DFS with map
     *
     * class Solution {
public:
    unordered_map<int, int> d;

    bool isEvenOddTree(TreeNode* root) {
        return dfs(root, 0);
    }

    bool dfs(TreeNode* root, int i) {
        if (!root) return true;
        int even = i % 2 == 0;
        int prev = d.count(i) ? d[i] : (even ? 0 : 1e6);
        if (even && (root->val % 2 == 0 || prev >= root->val)) return false;
        if (!even && (root->val % 2 == 1 || prev <= root->val)) return false;
        d[i] = root->val;
        return dfs(root->left, i + 1) && dfs(root->right, i + 1);
    }
};
     */
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * DFS with vector
     * TC: O(n)
     * SC: O(n)
     *
     * class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        TreeNode* current = root;
        return dfs(current, 0);
    }

private:
    vector<int> prev;
    bool dfs(TreeNode* current, size_t level) {
        // Base case, an empty tree is Even-Odd
        if (current == nullptr) {
            return true;
        }

        // Compare the parity of current and level
        if (current->val % 2 == level % 2) {
            return false;
        }

        // Resize prev to make room for the new level
        prev.resize(max(prev.size(), level + 1));

        // If there are previous nodes on this level, check increasing/decreasing
        // If on an even level, check that currrent's value is greater than the previous on this level
        // If on an odd level, check that current's value is less than the previous on this level
        if (prev[level] != 0 &&
                ((level % 2 == 0 && current->val <= prev[level]) ||
                 (level % 2 == 1 && current->val >= prev[level]))) {
            return false;  // Not in the required order
        }

        // Add current value to prev at index level
        prev[level] = current->val;

        // Recursively call DFS on the left and right children
        return dfs(current->left, level + 1) && dfs(current->right, level + 1);
    }
};

     */
};


#endif //DOOCS_EVENODDTREE_H
