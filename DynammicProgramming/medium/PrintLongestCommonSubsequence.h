//
// Created by Aldrin on 12-03-2024.
//

#ifndef DOOCS_PRINTLONGESTCOMMONSUBSEQUENCE_H
#define DOOCS_PRINTLONGESTCOMMONSUBSEQUENCE_H
#include "bits/stdc++.h"
using namespace std;

class PrintLongestCommonSubsequence {
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

        int len = dp[n][m];
        int index = len - 1;
        string ans = "";
        for(int i=1;i<=len;i++) {
            ans += "*";
        }

        while(n > 0 and m > 0) {
            if(s1[n - 1] == s2[m - 1]) {
                ans[index--] = s1[n-1];
                m--, n--;
            }
            else if(dp[n - 1][m] > dp[n][m - 1]) {
                n--;
            }
            else {
                m--;
            }
        }

        return ans;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    Time Complexity: O(n*m)

    Space Complexity: O(n*m)

    Where 'n' is length of string 's1' and 'm' is length of string 's2'.

// Function to calculate 'dp' array for LCS.
    void calculateLCS(int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = max(1 + dp[i - 1][j - 1], dp[i][j]);
                }
            }
        }
    }

    string findLCS(int n, int m, string &s1, string &s2)
    {
        // Initialising 'dp' array.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int i = n, j = m;
        string lcs;
        calculateLCS(n, m, s1, s2, dp);

        // Moving through 'dp[i][j]', if s1[i]==s2[j], the current character is a part
        // of 'lcs', else we move to the cell from which dp[i][j] got it's value, i.e.
        // maximum of dp[i-1][j] and dp[i][j-1].
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
                lcs.push_back(s1[i - 1]), i--, j--;
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }

        reverse(lcs.begin(), lcs.end());

        return lcs;
    }
     */
};


#endif //DOOCS_PRINTLONGESTCOMMONSUBSEQUENCE_H
