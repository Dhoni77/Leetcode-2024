//
// Created by Aldrin on 26-07-2022.
//

#ifndef DOOCS_LOWESTCOMMONANCESTOR_H
#define DOOCS_LOWESTCOMMONANCESTOR_H


class LowestCommonAncestor {
/*
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/
 *      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL)
            return right;
        if(right == NULL)
            return left;

        return root;
    }
 */
};


#endif //DOOCS_LOWESTCOMMONANCESTOR_H
