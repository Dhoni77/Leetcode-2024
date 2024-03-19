//
// Created by Aldrin on 19-03-2024.
//

#ifndef GEEKSFORGEEKS_VERTICALORDERTRAVERSALOFABINARYTREE_H
#define GEEKSFORGEEKS_VERTICALORDERTRAVERSALOFABINARYTREE_H
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

class VerticalOrderTraversalOfABinaryTree {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        int lvl = 0;
        nodes.emplace_back(0, 0, root->val);
        q.push({root, 0});
        while(!q.empty()) {
            lvl++;
            int sz = q.size();

            while(sz--) {
                auto node = q.front().first;
                int col = q.front().second;
                q.pop();
                if(node->left) {
                    q.push({node->left, col - 1});
                    nodes.emplace_back(col-1, lvl, node->left->val);
                }
                if(node->right) {
                    q.push({node->right, col + 1});
                    nodes.emplace_back(col+1, lvl, node->right->val);
                }
            }
        }
        sort(nodes.begin(), nodes.end());
        int prev = -2000;
        for(auto [col, _, val]: nodes) {
            if(prev != col) {
                prev = col;
                ans.emplace_back();
            }
            ans.back().push_back(val);
        }

        return ans;
    }
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
    class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            map<int,map<int,multiset<int>>>nodes;
            queue<pair<TreeNode*,pair<int,int>>>todo;
            todo.push({root,{0,0}});
            while(!todo.empty()){
                auto p=todo.front();
                todo.pop();
                TreeNode* node=p.first;
                int x=p.second.first,y=p.second.second;
                nodes[x][y].insert(node->val);
                if(node->left) todo.push({node->left,{x-1,y+1}});
                if(node->right) todo.push({node->right,{x+1,y+1}});
            }
            vector<vector<int>>ans;
            for(auto p:nodes){
                vector<int>col;
                for(auto q:p.second){
                    col.insert(col.end(),q.second.begin(),q.second.end());
                }
                ans.push_back(col);
            }
            return ans;;
        }
    };
     *
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:
        void Traverse(TreeNode* root, map<int, multiset<pair<int,int>> > &m,int left, int right){
            if(root==NULL){
                return;
            }
            m[right-left].insert( { (left+right) , (root->val) });
            Traverse(root->left,m,left+1,right);
            Traverse(root->right,m,left,right+1);
        }

        vector<vector<int>> verticalTraversal(TreeNode* root) {

            //the number of times we have moved left or right ..that decides our column and row number
            map<int,multiset<pair<int,int>> > m; //stores the data of nodes residing in a single column which is the key
            //key = column no. = no. of times right - no.of times left and row number = no. of times left + no. of times right

            int left=0, right=0;

            Traverse(root,m,left,right);

            vector<vector<int>> ans;

            for(auto &[key,vec]:m){
                vector<int> temp;
                for(auto &[x,y]:vec){
                    temp.push_back(y);
                }
                ans.push_back(temp);
            }

            return ans;
        }
    };
     */
};


#endif //GEEKSFORGEEKS_VERTICALORDERTRAVERSALOFABINARYTREE_H
