//
// Created by Aldrin on 12-03-2024.
//

#ifndef DOOCS_SHORTESTCOMMONSUPERSEQUENCE_H
#define DOOCS_SHORTESTCOMMONSUPERSEQUENCE_H
#include "bits/stdc++.h"
using namespace std;

class ShortestCommonSuperSequence {
public:
    string findLCS(int n, int m,string &s1, string &s2){
        // Write your code here.
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string ans = "";

        while(n > 0 and m > 0) {
            if(s1[n - 1] == s2[m - 1]) {
                ans += s1[n-1];
                m--, n--;
            }
            else if(dp[n - 1][m] > dp[n][m - 1]) {
                ans += s1[n-1];
                n--;
            }
            else {
                ans += s2[m-1];
                m--;
            }
        }

        while(n > 0) {
            ans += s1[n-1];
            n--;
        }

        while(m > 0) {
            ans += s2[m-1];
            m--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        return findLCS(str1.size(), str2.size(), str1, str2);
    }
};


#endif //DOOCS_SHORTESTCOMMONSUPERSEQUENCE_H
