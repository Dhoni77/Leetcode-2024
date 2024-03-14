//
// Created by Aldrin on 13-03-2024.
//

#ifndef DOOCS_BESTTIMETOBUYANDSELLSTOCKWITHTRANSACTIONFEE_H
#define DOOCS_BESTTIMETOBUYANDSELLSTOCKWITHTRANSACTIONFEE_H
#include "bits/stdc++.h"
using namespace std;

class BestTimeToBuyAndSellStockWithTransactionFee {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for(int ind=n-1;ind>=0;ind--) {
            for(int buy = 0;buy<2;buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }
                else {
                    profit = max((prices[ind] + dp[ind+1][1]) - fee, dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};


#endif //DOOCS_BESTTIMETOBUYANDSELLSTOCKWITHTRANSACTIONFEE_H
