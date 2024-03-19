//
// Created by Aldrin on 18-03-2024.
//

#ifndef DOOCS_MAXIMUMWIDTHOFBINARYTREE_H
#define DOOCS_MAXIMUMWIDTHOFBINARYTREE_H
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

class MaximumWidthOfBinaryTree {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        unsigned long long maxi = 0;
        
        while(!q.empty()) {
            int size = q.size();
            unsigned long long start = q.front().second;

            while(size--) {
                auto node = q.front().first;
                unsigned long long end = q.front().second;
                q.pop();
                
                if(node->left) {
                    q.push({node->left, 2 * end});
                }        
                
                if(node->right) {
                    q.push({node->right, (2*end)+1});    
                }
                
                maxi = max(maxi, end - start + 1);
            }
        }

        return maxi;
    }
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *  // Basically we use a Level-Order Traversal to find the width...with some otherworldly and simple modifications..
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;

        long long int ans = 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0});

        while(!q.empty()){
            long long int size = q.size();
            long long int mmin = q.front().second; // to make the id starting from Zero..!
            long long int first , last;

            for(int i = 0 ; i < size ; i++){
                long long int currId = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0)
                    first = currId;
                if( i == size - 1)
                    last = currId;

                if( node -> left )
                    q.push({node -> left , currId * 2 + 1});

                if(node -> right)
                    q.push({node -> right , currId * 2 + 2});
            }
            ans = max(ans , last - first + 1);
        }
        return ans;
    }
     */
};


#endif //DOOCS_MAXIMUMWIDTHOFBINARYTREE_H
