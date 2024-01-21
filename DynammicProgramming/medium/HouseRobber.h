//
// Created by Aldrin on 21-01-2024.
//

#ifndef DOOCS_HOUSEROBBER_H
#define DOOCS_HOUSEROBBER_H
#include "bits/stdc++.h"
using namespace std;

class HouseRobber {
public:
    /**
     * Explanation
     *  A robber has 2 options: a) rob current house i; b) don't rob current house.
        If an option "a" is selected it means she can't rob previous i-1 house but can safely proceed to the one before previous i-2 and gets all cumulative loot that follows.
        If an option "b" is selected the robber gets all the possible loot from robbery of i-1 and all the following buildings.
        So it boils down to calculating what is more profitable:

        robbery of current house + loot from houses before the previous
        loot from the previous house robbery and any loot captured before that
        rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )
     * **/
        int solve(int index, int sum, int n, vector<int> nums) {
            if(index < 0)
                return sum;
            int take = solve(index - 2, nums[index] + sum, n, nums);
            int nottake = solve(index - 1, sum, n, nums);

            return max(take, nottake);
        }

        int rob(vector<int> & nums) {
            int n = nums.size();
            return solve(n - 1, 0, n, nums);
        }
//-------------------------------------------------------------------------------------------------------------
        /*
         *   int rob(vector<int>& nums) {
                if (nums.empty())
                  return 0;
                if (nums.size() == 1)
                  return nums[0];

                // dp[i] := the maximum money of robbing nums[0..i]
                vector<int> dp(nums.size());
                dp[0] = nums[0];
                dp[1] = max(nums[0], nums[1]);

                for (int i = 2; i < nums.size(); ++i)
                  dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

                return dp.back();
              }
         */
//------------------------------------------------------------------------------------------------------------
       /*TC: O(N)
        * SC: O(1)
        * class Solution {
             public:
              int rob(vector<int>& nums) {
                int prev1 = 0;  // dp[i - 1]
                int prev2 = 0;  // dp[i - 2]

                for (const int num : nums) {
                  const int dp = max(prev1, prev2 + num);
                  prev2 = prev1;
                  prev1 = dp;
                }

                return prev1;
              }
            };
        */
};


#endif //DOOCS_HOUSEROBBER_H
