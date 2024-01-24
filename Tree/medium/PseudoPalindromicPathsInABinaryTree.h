//
// Created by Aldrin on 24-01-2024.
//

#ifndef DOOCS_PSEUDOPALINDROMICPATHSINABINARYTREE_H
#define DOOCS_PSEUDOPALINDROMICPATHSINABINARYTREE_H
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

class PseudoPalindromicPathsInABinaryTree {
public:
    int count = 0;

    int calculateBitSet(int oldBitSet, int val) {
        int newBitSet = oldBitSet;
        int mask = 1 << val;
        if(newBitSet & mask) {
            newBitSet = newBitSet ^ mask;
        }
        else {
            newBitSet |= mask;
        }
        return newBitSet;
    }

    void solve(TreeNode* root, int bitSet) {
        if(!root->left and !root->right) {
            int newBitSet = calculateBitSet(bitSet, root->val);
            int bitCount = 0;
            cout << newBitSet << endl;
            if((newBitSet & (newBitSet - 1)) == 0) {
                count++;
            }
            return;
        }

        int newBitSet = calculateBitSet(bitSet, root->val);
        if(root->left)
            solve(root->left, newBitSet);
        if(root->right)
            solve(root->right, newBitSet);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, 0);
        return count;
    }

    //-----------------------------------------------------------------------------------------------------------------------------
    /*
     * TC: O(N)
     * SC: O(H)
     *
     * class Solution {
 public:
      int pseudoPalindromicPaths(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
      }

     private:
      void dfs(TreeNode* root, int path, int& ans) {
        if (root == nullptr)
          return;
        if (root->left == nullptr && root->right == nullptr) {
          path ^= 1 << root->val;
          // we are checking if only one bit is set
          // check if at most one digit has an odd frequency
          if ((path & (path - 1)) == 0)
            ++ans;
          return;
        }

        dfs(root->left, path ^ 1 << root->val, ans);
        dfs(root->right, path ^ 1 << root->val, ans);
      }
    };
     */
    //---------------------------------------------------------------------------------------------------------------------------------
    /*
     * // Time Complexity: O(N) where N is the number of nodes
// Space Complexity: O(H) where H is the tree height
class Solution {
public:
    int ans = 0;

    // the idea is that there is at most one digit with odd frequency in pseudo-palindromic path
    // e.g. [2, 3, 3] - digit 2 has odd frequency
    // e.g. [9] - digit 9 has odd frequency
    // so that the digit with odd frequency can be put in the middle, e.g. 323, 9, etc
	// e.g. [2,2] - or no digit with odd frequency

    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return ans;
    }

    // if you don't know preorder traversal, try 144. Binary Tree Preorder Traversal first
    // Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
    // Explanation Link: https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/2549333/LeetCode-The-Hard-Way-DFS-or-Pre-Order-or-Explained-Line-By-Line
    void preorder(TreeNode* node, int cnt) {
        // preorder traversal step 1: if node is null, then return
        if (node == NULL) return;
        // preorder traversal step 2: do something with node value here

        // first let's understand what (x << y) means
        // (x << y): shifting `x` `y` bits to the left
        // e.g. 1 << 0 = 1 (shift 0 bit - stay as it is)
        // e.g. 1 << 1 = 0b10 (shift 1 bit - becomes 2)
        // e.g. 1 << 2 = 0b100 (shift 2 bits to the left - becomes 4)
        // you may find that (1 << n) is actually just power of 2. i.e. 2 ^ n

        // second let's understand three properties of XOR
        // 1. XOR is self-inverse which means x ^ x = 0 (number XOR number evaluates to 0)
        // 2. 0 is identity element which means x ^ 0 = x (number XOR 0 remains unchanged)
        // 3. XOR is commutative, which means x ^ y = y ^ x (order doesn't matter)

        // we can use (1 << i) to set the appearance of digit i
        // but how to count the odd frequency?
        // we can use above XOR properties to achieve the following
        // if the i-bit is set, then digit i has an odd frequency
        // how? remember XOR property #1, #2, and #3?
        // if a digit appears even number of times, the bit at the end will be 0. (x ^ x = 0)
        // if a digit appears odd number of times, the bit at the will be 1. (x ^ x ^ x = (x ^ x) ^ x = 0 ^ x = x)
        cnt ^= (1 << node->val);
        // do something at the leaf
        if (!node->left && !node->right) {
            // if i-bit is set in `cnt`, that means digit `i` has an odd frequency
            // therefore, the number of 1 in `cnt` = the number of digits with an odd frequency
            // however, we only want at most one digit that has an odd frequency
            // we can use a bit trick (n & (n - 1)) to remove the rightmost set bit.
            // e.g.
            // n     n     n - 1  n & (n - 1)
            // --   ----   ----   -------
            //  0   0000   0111    0000
            //  1   0001   0000    0000
            //  2   0010   0001    0000
            //  3   0011   0010    0010
            //  4   0100   0011    0000
            //  5   0101   0100    0100
            //  6   0110   0101    0100
            //  7   0111   0110    0110
            //  8   1000   0111    0000
            //  9   1001   1000    1000
            // 10   1010   1001    1000
            // 11   1011   1010    1010
            // 12   1100   1011    1000
            // 13   1101   1100    1100
            // 14   1110   1101    1100
            // 15   1111   1110    1110

            // if the result is 0, that means we have at most one digit that has an odd frequncy
            // hence, add one to ans
			// alternatively, you can use __builtin_popcount(cnt) <= 1 to check
            ans += (cnt & (cnt - 1)) == 0;
        }
        // preorder traversal step 3: traverse the left node
        preorder(node->left, cnt);
        // preorder traversal step 4: traverse the right node
        preorder(node->right, cnt);
    }
};
     */

};


#endif //DOOCS_PSEUDOPALINDROMICPATHSINABINARYTREE_H
