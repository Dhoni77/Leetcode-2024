//
// Created by Aldrin on 19-01-2024.
//

#ifndef DOOCS_MINIMUMFALLINGPATHSUM_H
#define DOOCS_MINIMUMFALLINGPATHSUM_H

#include "bits/stdc++.h"

using namespace std;

class MinimumFallingPathSum {
public:
    // (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
    // Memoization
    int solve(vector<vector<int>> matrix, int i, int j, int row, int col, vector<vector<int>> &dp) {
        if (i == row) {
            return matrix[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ld = INT_MAX;
        if (i + 1 <= row and j - 1 >= 0)
            ld = matrix[i][j] + solve(matrix, i + 1, j - 1, row, col, dp);
        int down = INT_MAX;
        if (i + 1 <= row)
            down = matrix[i][j] + solve(matrix, i + 1, j, row, col, dp);
        int rd = INT_MAX;
        if (i + 1 <= row and j + 1 <= col)
            rd = matrix[i][j] + solve(matrix, i + 1, j + 1, row, col, dp);

        return dp[i][j] = min({down, ld, rd});
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /**
     * Memoization
     *int f(int i,int j,int n,int m,vector<vector<int>>& a,vector<vector<int>>&dp)
        {
        if(j<0 || j>m-1)
            return 1e9;

        if(i==0)
            return a[i][j];

        if(dp[i][j]!=-1)
            return dp[i][j];

        int up = a[i][j] + f(i-1,j,n,m,a,dp);

        int ld = a[i][j] + f(i-1,j-1,n,m,a,dp);

        int rd = a[i][j] + f(i-1,j+1,n,m,a,dp);


        return dp[i][j]=min(up,min(ld,rd));

        }
     * **/

    // Tabulation(Bottom Up)
    int minFallingPathSu(vector<vector<int>> &matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, -1));
        // fill the starting cols
        for (int i = 0; i < c; i++) {
            dp[r - 1][i] = matrix[r - 1][i];
        }
        // Loop through the grid using two nested loops
        for (int i = r - 2; i >= 0; i--) {
            for (int j = 0; j < c; j++) {
                int ld = INT_MAX;
                if (i + 1 <= r - 1 and j - 1 >= 0)
                    ld = matrix[i][j] + dp[i + 1][j - 1];
                int down = INT_MAX;
                if (i + 1 <= r - 1)
                    down = matrix[i][j] + dp[i + 1][j];
                int rd = INT_MAX;
                if (i + 1 <= r - 1 and j + 1 <= c - 1)
                    rd = matrix[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min({down, ld, rd});
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<c;i++)
            ans = min(ans, dp[0][i]);
        return ans;
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /**
     *
     *  Tabulation (Top Bottom)
    class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld=1e9,rd=1e9;
                int up=matrix[i][j] + dp[i-1][j];

                if(j-1>=0)
                    ld=matrix[i][j] + dp[i-1][j-1];
                if(j+1<m)
                    rd=matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(up,min(ld,rd));
            }
        }
        int mini=dp[n-1][0];

        for(int j=1;j<m;j++)
        {
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }};
     * **/


    int minFallingPathSum(vector<vector<int>> &matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, -1));
        for (int i = 0; i < c; i++) {
            ans = min(ans, solve(matrix, 0, i, r - 1, c - 1, dp));
        }
        return ans;
    }
};


#endif //DOOCS_MINIMUMFALLINGPATHSUM_H
