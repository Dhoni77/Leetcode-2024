//
// Created by Aldrin on 03-01-2024.
//

#ifndef DOOCS_BESTTIMETOBUYANDSELLSTOCK_H
#define DOOCS_BESTTIMETOBUYANDSELLSTOCK_H
#include "bits/stdc++.h"
using namespace std;

class BestTimeToBuyAndSellStock {
public:
    /**
     * int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int start = 0;
        for(int i=0;i<prices.size()-1;i++) {
            start = prices[i];
            for(int j=i+1;j<prices.size();j++) {
                maxProfit = max(maxProfit, prices[j] - start);
            }
        }
        return maxProfit;
    }
     * **/
     //------------------------------------------------------------------------------------------------------------------------------
//     Time complexity: O(n)
//     Space Complexity: O(1)
     int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
     }
};


#endif //DOOCS_BESTTIMETOBUYANDSELLSTOCK_H
