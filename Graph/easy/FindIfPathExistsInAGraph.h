//
// Created by Aldrin on 21-04-2024.
//

#ifndef DOOCS_FINDIFPATHEXISTSINAGRAPH_H
#define DOOCS_FINDIFPATHEXISTSINAGRAPH_H
#include "bits/stdc++.h"
using namespace std;

class FindIfPathExistsInAGraph {
public:
    vector<int> p;
    int find(int node) {
        if(p[node] != node) {
            p[node] = find(p[node]);
        }
        return p[node];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        p =  vector<int>(n);
        iota(p.begin(), p.end(), 0);

        for(auto edge: edges) {
            p[find(edge[0])] = find(edge[1]);
        }

        return find(source) == find(destination);
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *     vector<bool> vis;
    vector<vector<int>> graph;

    void dfs(int node) {
        if(vis[node])
            return;
        vis[node] = true;

        for(int child: graph[node]) {
            if(!vis[child])
                dfs(child);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.resize(n, false);
        graph = vector<vector<int>>(n);
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(source);

        return vis[destination];
    }
     */
};


#endif //DOOCS_FINDIFPATHEXISTSINAGRAPH_H
