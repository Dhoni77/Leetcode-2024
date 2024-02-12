//
// Created by Aldrin on 11-02-2024.
//

#ifndef DOOCS_CHERRYPICKUPII_H
#define DOOCS_CHERRYPICKUPII_H
#include "bits/stdc++.h"
using namespace std;

class CherryPickupII {
public:
    vector<vector<vector<int>>> dp;
    int solve(int row, int r1, int r2, int n, int m, vector<vector<int>> grid) {
        if(row < 0 or r1 < 0 or r2 < 0 or row >= n or r1 >= m or r2 >= m) {
            return 0;
        }

        if(dp[row][r1][r2] != -1) {
            return dp[row][r1][r2];
        }

        int maxi = 0;
        int result = grid[row][r1] + grid[row][r2];

        for(int x=r1-1;x<=r1+1;x++) {
            for(int y=r2-1;y<=r2+1;y++) {
                if(x < y) {
                    maxi = max(maxi, solve(row + 1, x, y, n, m, grid));
                }
            }
        }

        result += maxi;
        return dp[row][r1][r2] = result;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
        return solve(0, 0, m-1, n, m, grid);
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *     int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n][n];
        memset(f, -1, sizeof(f));
        f[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[i - 1][y1][y2] != -1) {
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][y1][y2] + x);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = max(ans, f[m - 1][j1][j2]);
            }
        }
        return ans;
    }
     */
};


#endif //DOOCS_CHERRYPICKUPII_H
