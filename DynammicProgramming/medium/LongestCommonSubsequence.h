//
// Created by Aldrin on 25-01-2024.
//

#ifndef DOOCS_LONGESTCOMMONSUBSEQUENCE_H
#define DOOCS_LONGESTCOMMONSUBSEQUENCE_H
#include "bits/stdc++.h"
using namespace std;

class LongestCommonSubsequence {
public:
    int solve(string a, string b, int m, int n) {
        if(m == 0 || n == 0)
            return 0;

        if(a[m-1] == b[n - 1])
            return 1 + solve(a, b, m - 1, n - 1);

        return max(solve(a, b, m - 1, n), solve(a, b, m, n - 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        return solve(text1, text2, m, n);
    }
    //TC: O(MN)
    // SC: O(MN)
    int longestCommonSubsequenc(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
    int mod = 1e9 + 7;
    /*
     *  int recur(int i, int j, int row, int col, int moves, vector<vector<vector<int>>> &dp) {
//        printf("i: %d, j: %d, moves: %d\n", i, j, moves);
        if((i < 0 || j < 0 || i > row || j > col) and moves == 0)
            return 1;
        else if((i < 0 || j < 0 || i > row || j > col) and moves != 0)
            return 0;
        else if(i >= 0 and i <= row and j >= 0 and j <= col and moves == 0)
            return 0;

        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];

        long long left = recur(i, j - 1, row, col, moves - 1, dp);
        long long right = recur(i, j +  1, row, col, moves - 1, dp);
        long long up = recur(i - 1, j, row, col, moves - 1, dp);
        long long down = recur(i + 1, j, row, col, moves - 1, dp);

        return dp[i][j][moves] = (left + right + up + down) % mod;
    }

   int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        for(int i=1;i<=maxMove;i++) {
            ans = ans + recur(startRow, startColumn, m - 1, n - 1, i, dp);
        }
        return ans;
    }

     */
};


#endif //DOOCS_LONGESTCOMMONSUBSEQUENCE_H
