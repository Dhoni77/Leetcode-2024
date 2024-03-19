//
// Created by Aldrin on 18-03-2024.
//

#ifndef DOOCS_ALLNODESDISTANCEKINBINARYTREE_H
#define DOOCS_ALLNODESDISTANCEKINBINARYTREE_H
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

class AllNodesDistanceKInBinaryTree {
public:
    vector<int> ans;
    unordered_map<TreeNode*, pair<TreeNode*, bool>> mp;

    void dfs(TreeNode* root, int k) {
        if(root == nullptr or mp[root].second) {
            return;
        }
        mp[root].second = true;
        if(k-- == 0) {
            ans.push_back(root->val);
            return;
        }

        dfs(root->left, k);
        dfs(root->right, k);
        dfs(mp[root].first, k);
    }

    void parents(TreeNode* root, TreeNode* parent) {
        if(!root)
            return;
        mp[root] = make_pair(parent, false);
        parents(root->left, root);
        parents(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parents(root, nullptr);
        dfs(target, k);
        return ans;
    }
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:

        void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, int k){
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    parent[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parent[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }

        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_map<TreeNode*, TreeNode*> parent;
            makeParent(root, parent, k);

            unordered_map<TreeNode* , bool> visited;
            queue<TreeNode*> q;
            q.push(target);
            visited[target]=true;
            int level=0;
            while(!q.empty()){
                int n=q.size();
                if(level==k)
                    break;
                level++;
                for(int i=0; i<n; i++){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr->left && !visited[curr->left]){
                        q.push(curr->left);
                        visited[curr->left]=true;
                    }
                    if(curr->right && !visited[curr->right]){
                        q.push(curr->right);
                        visited[curr->right]=true;
                    }
                    if(parent[curr] && !visited[parent[curr]]){
                        q.push(parent[curr]);
                        visited[parent[curr]]=true;
                    }
                }
            }
            vector<int> ans;
            while(!q.empty()){
                TreeNode* curr=q.front();
                q.pop();
                ans.push_back(curr->val);
            }
            return ans;
        }
    };
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:

        void store_parents(TreeNode* root,map<TreeNode*,TreeNode*> &parent){
            if(root==NULL)
            {return ;}
            if(root->left)
            {
                parent[root->left]=root;
            }
            if(root->right)
            {
                parent[root->right]=root;
            }
            store_parents(root->left,parent);
            store_parents(root->right,parent);
        }

        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            map<TreeNode*,TreeNode*> parent; //stores parent
            store_parents(root,parent);

            map<TreeNode*,int> vis; //visited map
            int dist=0;
            queue<TreeNode*> q;
            q.push(target);
            vis[target]=1;



            while(!q.empty())
            {
                if(dist==k)
                {break;}
                int sz=q.size();
                for(int i=0;i<sz;i++)
                {
                    TreeNode* temp=q.front(); q.pop();
                    if(temp->left!=NULL && vis.find(temp->left)==vis.end())
                    {
                        q.push(temp->left); vis[temp->left]=1;
                    }
                    if(temp->right!=NULL && vis.find(temp->right)==vis.end())
                    {
                        q.push(temp->right); vis[temp->right]=1;
                    }
                    if(parent.find(temp)!=parent.end() && vis.find(parent[temp])==vis.end())
                    {
                        q.push(parent[temp]); vis[parent[temp]]=1;
                    }
                }
                dist++;
            }
            //when dist reaches k then queue stores our required set of nodes and we just store them in our answer
            vector<int> ans;
            while(!q.empty())
            {
                int temp=q.front()->val; q.pop();
                ans.push_back(temp);
            }
            return ans;
        }
    };
     */
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:

        void store_parents(TreeNode* root,map<TreeNode*,TreeNode*> &parent){
            if(root==NULL)
            {return ;}
            if(root->left)
            {
                parent[root->left]=root;
            }
            if(root->right)
            {
                parent[root->right]=root;
            }
            store_parents(root->left,parent);
            store_parents(root->right,parent);
        }

        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            map<TreeNode*,TreeNode*> parent; //stores parent
            store_parents(root,parent);

            map<TreeNode*,int> vis; //visited map
            int dist=0;
            queue<TreeNode*> q;
            q.push(target);
            vis[target]=1;



            while(!q.empty())
            {
                if(dist==k)
                {break;}
                int sz=q.size();
                for(int i=0;i<sz;i++)
                {
                    TreeNode* temp=q.front(); q.pop();
                    if(temp->left!=NULL && vis.find(temp->left)==vis.end())
                    {
                        q.push(temp->left); vis[temp->left]=1;
                    }
                    if(temp->right!=NULL && vis.find(temp->right)==vis.end())
                    {
                        q.push(temp->right); vis[temp->right]=1;
                    }
                    if(parent.find(temp)!=parent.end() && vis.find(parent[temp])==vis.end())
                    {
                        q.push(parent[temp]); vis[parent[temp]]=1;
                    }
                }
                dist++;
            }
            //when dist reaches k then queue stores our required set of nodes and we just store them in our answer
            vector<int> ans;
            while(!q.empty())
            {
                int temp=q.front()->val; q.pop();
                ans.push_back(temp);
            }
            return ans;
        }
    };
     */
};


#endif //DOOCS_ALLNODESDISTANCEKINBINARYTREE_H
