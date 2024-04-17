//
// Created by Aldrin on 17-04-2024.
//

#ifndef DOOCS_SMALLESTSTRINGSTARTINGFROMLEAF_H
#define DOOCS_SMALLESTSTRINGSTARTINGFROMLEAF_H
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


class SmallestStringStartingFromLeaf {
public:
    string result = "~";
    void solve(TreeNode* root, string &path) {
        if(!root) {
            return;
        }
        path += ('a' + root->val);
        if(root->left == nullptr and root->right == nullptr) {
            string temp = path;
            reverse(temp.begin(), temp.end());
            result = min(result, temp);
            return;
        }
        solve(root->left, path);
        solve(root->right, path);
        path.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        solve(root, path);
        return result;
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    string smallestString;

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallestString;
    }

    // Helper function to find the lexicographically smallest string
    void dfs(TreeNode* root, string currentString) {

        // If the current node is NULL, return
        if (!root) {
            return;
        }

        // Construct the current string by appending
        // the character corresponding to the node's value
        currentString = char(root->val + 'a') + currentString;

        // If the current node is a leaf node
        if (!root->left && !root->right) {

            // If the current string is smaller than the result
            // or if the result is empty
            if (smallestString == "" || smallestString > currentString) {
                smallestString = currentString;
            }
        }

        // Recursively traverse the left subtree
        if (root->left) {
            dfs(root->left, currentString);
        }

        // Recursively traverse the right subtree
        if (root->right) {
            dfs(root->right, currentString);
        }
    }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string smallestString = "";
        queue<pair<TreeNode*, string>> nodeQueue;

        // Add root node to queue along with its value converted to a character
        nodeQueue.push({root, string(1, root->val + 'a')});

        // Perform BFS traversal until queue is empty
        while (!nodeQueue.empty()) {

            // Pop the leftmost node and its corresponding string from queue
            auto[node, currentString] = nodeQueue.front();
            nodeQueue.pop();

            // If current node is a leaf node
            if (!node->left && !node->right) {

                // Update smallest_string if it's empty or current string is smaller
                if (smallestString.empty()) {
                    smallestString = currentString;
                } else {
                    smallestString = min(smallestString, currentString);
                }
            }

            // If current node has a left child, append it to queue
            if (node->left) {
                nodeQueue.push({node->left, char(node->left->val + 'a') + currentString});
            }

            // If current node has a right child, append it to queue
            if (node->right) {
                nodeQueue.push({node->right, char(node->right->val + 'a') + currentString});
            }
        }

        return smallestString;
    }
};
     */
};


#endif //DOOCS_SMALLESTSTRINGSTARTINGFROMLEAF_H
