//
// Created by Aldrin on 29-02-2024.
//

#ifndef DOOCS_ZEROONEMATRIX_H
#define DOOCS_ZEROONEMATRIX_H
#include "bits/stdc++.h"
using namespace std;

class ZeroOneMatrix {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> dirs{-1, 0, 1, 0, -1};
        int row = mat.size(), col = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(row, vector<int>(col, -1));

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int x = node.first + dirs[i], y = node.second + dirs[i+1];
                if(x >= 0 and y >= 0 and x < row and y < col and ans[x][y] == -1) {
                    ans[x][y] = ans[node.first][node.second] + 1;
                    q.emplace(x, y);
                }
            }
        }

        return ans;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * Without Extra Space (BFS)
     *
     *   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = mat.size();
    const int n = mat[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 0)
          q.emplace(i, j);
        else
          mat[i][j] = INT_MAX;

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (mat[x][y] != INT_MAX)
          continue;
        q.emplace(x, y);
        mat[x][y] = mat[i][j] + 1;
      }
    }

    return mat;
  }
     */
};


#endif //DOOCS_ZEROONEMATRIX_H
