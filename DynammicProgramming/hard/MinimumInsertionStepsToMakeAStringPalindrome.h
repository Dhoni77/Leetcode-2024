//
// Created by Aldrin on 11-03-2024.
//

#ifndef DOOCS_MINIMUMINSERTIONSTEPSTOMAKEASTRINGPALINDROME_H
#define DOOCS_MINIMUMINSERTIONSTEPSTOMAKEASTRINGPALINDROME_H
#include "bits/stdc++.h"
using namespace std;

class MinimumInsertionStepsToMakeAStringPalindrome {
public:
    int minInsertions(string s) {
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

        return n - dp[n][n];
    }
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[i][i]=0;
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    dp[i][j]=min(dp[i][j-1], dp[i+1][j])+1;
                }
            }
        }
        return dp[0][n-1];
    }
};
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     * Space Optimization
     *
     * class Solution {
public:
    int lcs(string& s1, string& s2, int m, int n) {
        vector<int> dp(n + 1), dpPrev(n + 1);

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // One of the two strings is empty.
                    dp[j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp;
        }

        return dp[n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());

        return n - lcs(s, sReverse, n, n);
    }
};
     */
};


#endif //DOOCS_MINIMUMINSERTIONSTEPSTOMAKEASTRINGPALINDROME_H
