//
// Created by Aldrin on 03-02-2024.
//

#ifndef DOOCS_PARTITIONARRAYFORMAXIMUMSUM_H
#define DOOCS_PARTITIONARRAYFORMAXIMUMSUM_H
#include "bits/stdc++.h"
using namespace std;

class PartitionArrayForMaximumSum {
public:
    vector<int> dp;
    int solve(int start, int k, int n, vector<int> arr) {
        if(start >= n) {
            return 0;
        }

        if(dp[start] != 0)
            return dp[start];

        int maxi = INT_MIN, ans = INT_MIN;

        for(int j=start;j < min(n, start + k);j++) {
            maxi = max(maxi, arr[j]);
            ans = max(ans, (j - start + 1) * maxi + solve(j + 1, k, n, arr));
        }

        return dp[start] = ans;
    }

/*
 *     Memoization
 *     int maxSumAfterPartitioning(vector<int>& arr, int k) {
            int n = arr.size();
            dp.resize(n+1);
            return solve(0, k, n, arr);
        }
 */
//---------------------------------------------------------------------------------------------------------------------------------------
    // Tabulation
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.resize(n+1);
        for(int i=n-1;i>=0;i--) {
            int maxi = INT_MIN, ans = INT_MIN;
            for(int j=i;j<min(n, i + k);j++) {
                maxi = max(maxi, arr[j]);
                ans = max(ans, (j - i + 1) * maxi + dp[j+1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
    //----------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            int n = arr.size();
            int f[n + 1];
            memset(f, 0, sizeof(f));
            for (int i = 1; i <= n; ++i) {
                int mx = 0;
                for (int j = i; j > max(0, i - k); --j) {
                    mx = max(mx, arr[j - 1]);
                    f[i] = max(f[i], f[j - 1] + mx * (i - j + 1));
                }
            }
            return f[n];
        }
};
     */
    //--------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
 public:
      int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
          int maxi = INT_MIN;
          for (int j = 1; j <= min(i, k); ++j) {
            maxi = max(maxi, arr[i - j]);
            dp[i] = max(dp[i], dp[i - j] + maxi * j);
          }
        }

        return dp[n];
      }
};
     */
};


#endif //DOOCS_PARTITIONARRAYFORMAXIMUMSUM_H
