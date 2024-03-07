//
// Created by Aldrin on 07-03-2024.
//

#ifndef DOOCS_SUBSET_TARGETSUM_H
#define DOOCS_SUBSET_TARGETSUM_H
#include "bits/stdc++.h"
using namespace std;

class Subset_TargetSum {
public:
    int findWays(vector<int>& arr, int k)
    {
        // Write your code here.
        int n = arr.size();
        long long modulo = 1e9+7;
        sort(arr.begin(), arr.end(), greater<int>());
        // Needed to sort for this test case {0, 0, 1} and k = 1
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;  // 2 cases - pick and not pick
        else
            dp[0][0] = 1;  // 1 case - not pick

        if (arr[0] != 0 && arr[0] <= k)
            dp[0][arr[0]] = 1;  // 1 case - pick

        for(int ind=1;ind<n;ind++) {
            for(int target = 0;target<=k;target++) {
                int pick = 0;
                if(arr[ind] <= target) {
                    pick = dp[ind-1][target-arr[ind]];
                }
                int notpick = dp[ind-1][target];
                dp[ind][target] = (pick + notpick) % modulo;
            }
        }

        return dp[n-1][k];
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        // Write your code here.
        int sum = accumulate(arr.begin(), arr.end(), 0);
        /*
         * sum - diff must be even since we cannot have decimal values and greater >= 0
         */
        if((sum - d < 0) or (sum - d) % 2)
            return 0;
        int s2 = (sum - d) / 2;

        return findWays(arr, s2);
    }

    int findTargetSumWays(vector<int>& arrs, int target) {
        int n = arrs.size();

        return countPartitions(n, target, arrs);
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target) || (sum + target) & 1)
      return 0;
    return knapsack(nums, (sum + target) / 2);
  }

 private:
  int knapsack(const vector<int>& nums, int target) {
    const int n = nums.size();
    // dp[i][j] := the number of ways to sum to j by nums[0..i)
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      const int num = nums[i - 1];
      for (int j = 0; j <= target; ++j)
        if (j < num)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
    }

    return dp[n][target];
  }
};
     */
};


#endif //DOOCS_SUBSET_TARGETSUM_H
