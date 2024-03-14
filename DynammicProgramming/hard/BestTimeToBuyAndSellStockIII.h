//
// Created by Aldrin on 13-03-2024.
//

#ifndef DOOCS_BESTTIMETOBUYANDSELLSTOCKIII_H
#define DOOCS_BESTTIMETOBUYANDSELLSTOCKIII_H
#include "bits/stdc++.h"
using namespace std;

class BestTimeToBuyAndSellStockIII {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        dp[n][0][2] = dp[n][1][2] = 0;

        for(int ind=n-1;ind>=0;ind--) {
            for(int buy = 0;buy<2;buy++) {
                for(int capacity = 1;capacity <=2;capacity++) {
                    if(buy) {
                        dp[ind][buy][capacity] = max(-prices[ind] + dp[ind+1][0][capacity], dp[ind+1][1][capacity]);
                    }
                    else {
                        dp[ind][buy][capacity] = max(prices[ind] + dp[ind+1][1][capacity-1], dp[ind+1][0][capacity]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};


#endif //DOOCS_BESTTIMETOBUYANDSELLSTOCKIII_H
