//
// Created by Aldrin on 10-01-2024.
//

#ifndef DOOCS_AMOUNTOFTIMEFORBINARYTREETOBEINFECTED_H
#define DOOCS_AMOUNTOFTIMEFORBINARYTREETOBEINFECTED_H
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

class AmountOfTimeForBinaryTreeToBeInfected {
public:
    // TC: O(N)
    // SC: O(N)
  int amountOfTime(TreeNode* root, int start) {
            unordered_map<int, unordered_set<int>> map;
            convert(root, 0, map);
            queue<int> q;
            q.push(start);
            int minute = 0;
            unordered_set<int> visited;
            visited.insert(start);

            while (!q.empty()) {
                int levelSize = q.size();
                while (levelSize > 0) {
                    int current = q.front();
                    q.pop();

                    for (int num : map[current]) {
                        if (visited.find(num) == visited.end()) {
                            visited.insert(num);
                            q.push(num);
                        }
                    }
                    levelSize--;
                }
                minute++;
            }
            return minute - 1;
        }

        void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& map) {
            if (current == nullptr) {
                return;
            }
            if (map.find(current->val) == map.end()) {
                map[current->val] = unordered_set<int>();
            }
            unordered_set<int>& adjacentList = map[current->val];
            if (parent != 0) {
                adjacentList.insert(parent);
            }
            if (current->left != nullptr) {
                adjacentList.insert(current->left->val);
            }
            if (current->right != nullptr) {
                adjacentList.insert(current->right->val);
            }
            convert(current->left, current->val, map);
            convert(current->right, current->val, map);
        }
    //------------------------------------------------------------------------------------------------------------------------------------------------------
    /**
     *     unordered_map<int, vector<int>> g;

    int amountOfTime(TreeNode* root, int start) {
        buildAdjacencyList(root);
        return dfs(start, -1);
    }

    int dfs(int start, int parent) {
        int ans = 0;
        for(int node: g[start]) {
            if(node != parent) {
                ans = max(ans, 1 + dfs(node, start));
            }
        }
        return ans;
    }

   void buildAdjacencyList(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        if(root->left) {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
        }
        if(root->right) {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
        }
       buildAdjacencyList(root->left);
       buildAdjacencyList(root->right);
    }
     * **/
};


#endif //DOOCS_AMOUNTOFTIMEFORBINARYTREETOBEINFECTED_H
