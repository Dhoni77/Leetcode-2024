//
// Created by Aldrin on 25-04-2024.
//

#ifndef DOOCS_LONGESTIDEALSUBSEQUENCE_H
#define DOOCS_LONGESTIDEALSUBSEQUENCE_H
#include "bits/stdc++.h"
using namespace std;

class LongestIdealSubsequence {
public:
        int longestIdealString(string s, int k) {
            int N = s.size();
            vector<int> dp(26, 0);

            int res = 0;
            // Updating dp with the i-th character
            for (int i = 0; i < N; i++) {
                int curr = s[i] - 'a';
                int best = 0;
                for (int prev = 0; prev < 26; prev++) {
                    if (abs(prev - curr) <= k) {
                        best = max(best, dp[prev]);
                    }
                }

                // Appending s[i] to the previous longest ideal subsequence allowed
                dp[curr] = max(dp[curr], best + 1);
                res = max(res, dp[curr]);
            }
            return res;
        }
        //---------------------------------------------------------------------------------------------------------------------
        /*
         *
         * class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = size(s);
        vector<vector<int>> dp(N, vector<int>(26, -1));

        // Find the maximum dp[N-1][c] and return the result
        int res = 0;
        for (int c = 0; c < 26; c++) {
            res = max(res, dfs(N - 1, c, dp, s, k));
        }
        return res;
    }

    int dfs(int i, int c, vector<vector<int>>& dp, string& s, int k) {
        // Memoized value
        if (dp[i][c] != -1) {
            return dp[i][c];
        }

        // State is not visited yet
        dp[i][c] = 0;
        bool match = c == (s[i] - 'a');
        if (match) {
            dp[i][c] = 1;
        }

        // Non base case handling
        if (i > 0) {
            dp[i][c] = dfs(i - 1, c, dp, s, k);
            if (match) {
                for (int p = 0; p < 26; p++) {
                    if (abs(c - p) <= k) {
                        dp[i][c] = max(dp[i][c], dfs(i - 1, p, dp, s, k) + 1);
                    }
                }
            }
        }
        return dp[i][c];
    }
};
         */
        //---------------------------------------------------------------------------------------------------------------------
        /*
         *
         * class Solution {
private:
    int solve(int ind, string &s, int prev, int k, vector<vector<int>> &dp) {
        if(ind == 0) { // instead of -1 this will be 0
            return 0;
        }

        if(dp[ind][prev] != -1)
            return dp[ind][prev];

        int take = 0;
        int ch = s[ind - 1] - 'a' + 1; // have to maintain the indices of the string too

        if (prev == 0 or abs(ch - prev) <= k) {
            take = solve(ind - 1, s, ch, k, dp) + 1;
        }

        int notTake = solve(ind - 1, s, prev, k, dp);
        return dp[ind][prev] = max(take, notTake);
    }
public:

    int longestIdealString(string s, int k) {

        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(27, -1));

        return solve(n, s, 0, k, dp);
    }
};
         */
        //----------------------------------------------------------------------------------------------------------------------
        /*
         *
         * class Solution {
private:
    int solve(int ind, string &s, int prev, int k, vector<vector<int>> &dp) {
        if(ind == -1) {
            return 0;
        }

        if(dp[ind][prev] != -1)
            return dp[ind][prev];

        int take = 0;
        int ch = s[ind] - 'a' + 1;

        if (prev == 0 or abs(ch - prev) <= k) {
            take = solve(ind - 1, s, ch, k, dp) + 1;
        }

        int notTake = solve(ind - 1, s, prev, k, dp);
        return dp[ind][prev] = max(take, notTake);
    }
public:

    int longestIdealString(string s, int k) {

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(27, -1)); // 27 because space for 26 alphabets and one more for '0';

        return solve(n - 1, s, 0, k, dp);
    }
};
         */
};


#endif //DOOCS_LONGESTIDEALSUBSEQUENCE_H
