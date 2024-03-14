//
// Created by Aldrin on 12-03-2024.
//

#ifndef DOOCS_DISTINCTSUBSEQUENCES_H
#define DOOCS_DISTINCTSUBSEQUENCES_H
#include "bits/stdc++.h"
using namespace std;

class DistinctSubsequences {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        unsigned long long dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for(int i=0;i<=m;i++) {
            dp[i][0] = 1;
        }

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[m][n];
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * With mod
     *
     *     int numDistinct(string s, string t) {
        int m = s.size(), n = t.size(), mod = 1e9+7;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i=0;i<=m;i++) {
            dp[i][0] = 1;
        }

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[m][n];
    }
     */
};


#endif //DOOCS_DISTINCTSUBSEQUENCES_H
