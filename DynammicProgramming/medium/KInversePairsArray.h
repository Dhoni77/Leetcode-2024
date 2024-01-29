//
// Created by Aldrin on 27-01-2024.
//

#ifndef DOOCS_KINVERSEPAIRSARRAY_H
#define DOOCS_KINVERSEPAIRSARRAY_H
#include "bits/stdc++.h"
using namespace std;

class KInversePairsArray {
public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int solve(int n, int k) {
        if(k == 0)
            return 1;
        if(n == 0)
            return 0;

        if(dp[n][k] != -1)
            return dp[n][k];

        int count = 0;

        for(int i=0;i<=min(n-1, k);i++) {
            count = (count + solve(n - 1, k - i)) % mod;
        }

        return dp[n][k] = count;
    }

    int kInversePairs(int n, int k) {
        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(n, k);
    }

    int kInversePair(int N, int K) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));

        for(int n=1;n<=N;n++) {
            for(int k=0;k<=K;k++) {
                if(k == 0)
                {
                    dp[n][k] = 1;
                    continue;
                }
                for(int i=0;i<min(n, k-1);i++) {
                    dp[n][k] = (dp[n][k] + dp[n - 1][k - i]) % mod;
                }
            }
        }

        return dp[N][K];
    }
    //-----------------------------------------------------------------------------------------------------------------------------------
    /*
     * int kInversePairs(int N, int K) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        for(int n=1;n<=N;n++) {
            for(int k=0;k<=K;k++) {
                if(k == 0)
                {
                    dp[n][k] = 1;
                    continue;
                }
                for(int i=0;i<=min(k, n-1);i++) {
                    dp[n][k] = (dp[n][k] + dp[n - 1][k - i]) % mod;
                }
            }
        }

        return dp[N][K];
    }
     */
    //------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
 public:
      int kInversePairs(int n, int k) {
        constexpr int kMod = 1'000'000'007;
        // dp[i][j] := the number of permutations of numbers 1..i with j inverse
        // pairs
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));

        // If there's no inverse pair, the permutation is unique "123..i".
        for (int i = 0; i <= n; ++i)
          dp[i][0] = 1;

        for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= k; ++j) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % kMod;
            if (j - i >= 0)
              dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + kMod) % kMod;
          }

        return dp[n][k];
      }
};
     */
};


#endif //DOOCS_KINVERSEPAIRSARRAY_H
