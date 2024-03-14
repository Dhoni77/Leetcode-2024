//
// Created by Aldrin on 13-03-2024.
//

#ifndef DOOCS_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H
#define DOOCS_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H
#include "bits/stdc++.h"
using namespace std;

class BestTimeToBuyAndSellStockWithCoolDown {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int ind=n-1;ind>=0;ind--) {
            for(int buy = 0;buy<2;buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }
                else {
                    profit = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][0];
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
            public:
                int getAns(vector<int> &Arr, int ind, int buy, int n, vector<vector<int>> &dp) {
                // Base case: When we reach the end of the array, there are no more decisions to make.
                if (ind >= n) {
                    return 0;
                }

                // If the result for this state has already been calculated, return it
                if (dp[ind][buy] != -1) {
                    return dp[ind][buy];
                }

                int  profit = 0;

                if (buy == 0) { // We can buy the stock
                    profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
                }

                if (buy == 1) { // We can sell the stock
                    profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 2, 0, n, dp));
                }

                // Store the calculated profit in the DP table and return it
                return dp[ind][buy] = profit;
            }
                int maxProfit(vector<int>& prices) {
                    int n = prices.size();
                    vector<vector<int>> dp(n, vector<int>(2, -1));
                    return getAns(prices, 0, 0, n, dp);
                }
            };
     */
};


#endif //DOOCS_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H
