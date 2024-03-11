//
// Created by Aldrin on 11-03-2024.
//

#ifndef DOOCS_LONGESTPALINDROMICSUBSEQUENCE_H
#define DOOCS_LONGESTPALINDROMICSUBSEQUENCE_H
#include "bits/stdc++.h"
using namespace std;

class LongestPalindromicSubsequence {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(t[i-1] == s[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
     */
    //
};


#endif //DOOCS_LONGESTPALINDROMICSUBSEQUENCE_H
