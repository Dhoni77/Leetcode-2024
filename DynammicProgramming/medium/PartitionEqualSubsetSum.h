//
// Created by Aldrin on 05-03-2024.
//

#ifndef DOOCS_PARTITIONEQUALSUBSETSUM_H
#define DOOCS_PARTITIONEQUALSUBSETSUM_H
#include "bits/stdc++.h"
using namespace std;

class PartitionEqualSubsetSum {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));

        // when target is 0 then true
        for(int i=0;i<n;i++) {
            dp[i][0] = true;
        }

        // when ind = 0, then if target equals a[0] then T
        dp[0][arr[0]] = true;

        for(int ind=1;ind<n;ind++) {
            for(int target=1;target<=k;target++) {
                bool pick = false;
                if(arr[ind] <= target) {
                    pick =  dp[ind - 1][target - arr[ind]];
                }
                bool notPick = dp[ind-1][target];

                dp[ind][target] = pick or notPick;
            }
        }

        return dp[n-1][k];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;
        return subsetSumToK(nums.size(), target, nums);
    }
};


#endif //DOOCS_PARTITIONEQUALSUBSETSUM_H
