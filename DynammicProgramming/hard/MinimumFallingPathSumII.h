//
// Created by Aldrin on 26-04-2024.
//

#ifndef DOOCS_MINIMUMFALLINGPATHSUMII_H
#define DOOCS_MINIMUMFALLINGPATHSUMII_H
#include "bits/stdc++.h"
using namespace std;

class MinimumFallingPathSumII {
public:
    // TC: O(N^3)
    // SC: O(N^2)
    int f(int i, int j, int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == 0) {
            return grid[i][j];
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int minVal = 1e9;
        for(int t = col;t>=0;t--) {
            if(t != j) {
                minVal = min(minVal, grid[i][j] + f(i - 1, t, row, col, grid, dp));
            }
        }

        return dp[i][j] = minVal;
    }

    int minFallingPathSu(vector<vector<int>> &grid) {
        vector<vector<int>> dp = grid;
        int row = grid.size();
        int col = grid[0].size();
        int ans = 1e9;

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++){
                int minVal = 1e9;
                for(int t=0;i-1 >= 0 and t<col;t++) {
                    if(t!=j) {
                        minVal = min(minVal, dp[i-1][t]);
                    }
                }
                minVal != 1e9 ? dp[i][j] += minVal : dp[i][j] += 0;
                if(row - 1 == i) {
                    ans = min(ans, dp[row-1][j]);
                }
            }
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, -1));
        for (int i = c - 1; i >= 0; i--) {
            ans = min(ans, f(r - 1, i, r-1, c-1, grid, dp));
        }
        return ans;
    }
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int f[n + 1][n];
        memset(f, 0, sizeof(f));
        const int inf = 1 << 30;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = inf;
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        x = min(x, f[i - 1][k]);
                    }
                }
                f[i][j] = grid[i - 1][j] + (x == inf ? 0 : x);
            }
        }
        return *min_element(f[n], f[n] + n);
    }
};
     */
};


#endif //DOOCS_MINIMUMFALLINGPATHSUMII_H
