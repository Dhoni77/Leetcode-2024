//
// Created by Aldrin on 23-04-2024.
//

#ifndef DOOCS_MINIMUMHEIGHTTREES_H
#define DOOCS_MINIMUMHEIGHTTREES_H
#include "bits/stdc++.h"
using namespace std;

class MinimumHeightTrees {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> deg(n, 0), result;
        queue<int> q;

        if(n <= 0)
            return result;

        if(n == 1) {
            return {0};
        }

        for(auto edge: edges) {
            deg[edge[0]]++;
            deg[edge[1]]++;

            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++) {
            if(deg[i] == 1) {
                q.push(i);
            }
        }

        while(n > 2) {
            int sz = q.size();
            n -= sz;

            while(sz > 0) {
                int el = q.front();
                q.pop();

                for(int ne: graph[el]) {
                    deg[ne]--;
                    if(deg[ne] == 1)
                        q.push(ne);
                }
                sz--;
            }
        }

        while(!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> g(n);
        vector<int> degree(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
            ++degree[a];
            ++degree[b];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.clear();
            for (int i = q.size(); i > 0; --i) {
                int a = q.front();
                q.pop();
                ans.push_back(a);
                for (int b : g[a]) {
                    if (--degree[b] == 1) {
                        q.push(b);
                    }
                }
            }
        }
        return ans;
    }
};
     */
};


#endif //DOOCS_MINIMUMHEIGHTTREES_H
