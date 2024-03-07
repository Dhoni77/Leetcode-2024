//
// Created by Aldrin on 07-03-2024.
//

#ifndef DOOCS_COINCHANGEII_H
#define DOOCS_COINCHANGEII_H
#include "bits/stdc++.h"
using namespace std;

class CoinChangeII {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i) {
            int coin = coins[i];
            for (int j = 1; j <= amount; ++j) {
                int excluding = dp[j];
                if (coin <= j) {
                    int including = dp[j - coin];
                    dp[j] = excluding + including;
                }
            }
        }
        return dp.back();
    }
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
private:
    int coinChange2(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        // base case
        if(ind == 0)
        {
            return (target % coins[0] == 0);
        }

        if(dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        int notPick = coinChange2(ind - 1, target, coins, dp);
        int pick = 0;
        if(coins[ind] <= target)
        {
            pick = coinChange2(ind, target - coins[ind], coins, dp);
            // THUMB RULE:
            // In all the questions which states: "Can be used any number
            // of times - Infinite Supply!!", we DON'T MOVE BACK to the
            // previous index.
            }

        return dp[ind][target] = pick + notPick;

        // T.C. = O(N * Target)
        // S.C. = O(N * Target) + O(target) [DP Array Size + Stack Space]
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return coinChange2(n - 1, amount, coins, dp);
    }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int j = 0; j < coins.size(); j++)
        {
            for(int i = 1; i < amount+1; i++)
            {

                if(i >= coins[j])
                {
                    dp[i] +=  dp[i - coins[j]];
                }
            }
        }
        return dp[amount];
    }
};
     *
     */
};


#endif //DOOCS_COINCHANGEII_H
