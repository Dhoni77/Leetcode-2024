//
// Created by Aldrin on 01-03-2024.
//

#ifndef DOOCS_NUMBEROFENCLAVES_H
#define DOOCS_NUMBEROFENCLAVES_H
#include "bits/stdc++.h"
using namespace std;

class NumberOfEnclaves {
public:
    // BFS
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        vector<int> dirs{-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;

        if(grid.size()<2) return 0;

        for(int i=0;i<row;i++){
            if(grid[i][0]) {
                q.emplace(i,0);
                grid[i][0] = 0;
            }
            if(grid[i][col-1]) {
                q.emplace(i,col-1);
                grid[i][col-1] = 0;
            }
        }

        for(int j=1;j<grid[0].size();j++){
            if(grid[0][j]) {
                q.emplace(0,j);
                grid[0][j] = 0;
            }
            if(grid[row-1][j]) {
                q.emplace(row-1,j);
                grid[row-1][j] = 0;
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int x = node.first + dirs[i], y = node.second + dirs[i+1];
                if(x < 0 or y < 0 or x == row or y == col or grid[x][y] != 1)
                    continue;
                q.emplace(x, y);
                grid[x][y] = 0;
            }
        }

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j])
                    ans++;
            }
        }

        return ans;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * DFS
     *
     * class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int)> dfs = [&](int i, int j) {
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    dfs(x, y);
                }
            }
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    dfs(i, j);
                }
            }
        }
        int ans = 0;
        for (auto& row : grid) {
            for (auto& v : row) {
                ans += v;
            }
        }
        return ans;
    }
};
     */
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * BFS
     *
     * class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    q.emplace(x, y);
                    grid[x][y] = 0;
                }
            }
        }
        int ans = 0;
        for (auto& row : grid) {
            for (auto& v : row) {
                ans += v;
            }
        }
        return ans;
    }
};
     */
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Union Find
     *
     * class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n + 1);
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        uf.unite(i * n + j, m * n);
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dirs[k], y = j + dirs[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                uf.unite(i * n + j, x * n + y);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                ans += grid[i][j] == 1 && uf.find(i * n + j) != uf.find(m * n);
            }
        }
        return ans;
    }
};
     */
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * DFS with accumulator
     *
     * class Solution {
 public:
  int numEnclaves(vector<vector<int>>& A) {
    const int m = A.size();
    const int n = A[0].size();

    // Remove the lands connected to the edge.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (A[i][j] == 1)
            dfs(A, i, j);

    return accumulate(A.begin(), A.end(), 0, [](int s, vector<int>& row) {
      return s + accumulate(row.begin(), row.end(), 0);
    });
  }

 private:
  void dfs(vector<vector<int>>& A, int i, int j) {
    if (i < 0 || i == A.size() || j < 0 || j == A[0].size())
      return;
    if (A[i][j] == 0)
      return;

    A[i][j] = 0;
    dfs(A, i + 1, j);
    dfs(A, i - 1, j);
    dfs(A, i, j + 1);
    dfs(A, i, j - 1);
  };
};
     */
};


#endif //DOOCS_NUMBEROFENCLAVES_H
