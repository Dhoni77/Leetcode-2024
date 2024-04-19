//
// Created by Aldrin on 19-04-2024.
//

#ifndef DOOCS_NUMBEROFISLANDS_H
#define DOOCS_NUMBEROFISLANDS_H
#include "bits/stdc++.h"
using namespace std;

class NumberOfIslands {
public:
    vector<int> dirs = {-1, 0, 1, 0, -1};
    void dfs(int i, int j, int row, int col, vector<vector<char>> &mat) {
        if(i < 0 or j < 0 or i == row or j == col or mat[i][j] == '0') {
            return;
        }

        mat[i][j] = '0';

        for (int k = 0; k < 4; ++k)
        {
            int x = i + dirs[k], y = j + dirs[k + 1];
            dfs(x, y, row, col, mat);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), count = 0;

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, row, col, grid);
                    count++;
                }
            }
        }

        return count;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
};


#endif //DOOCS_NUMBEROFISLANDS_H
