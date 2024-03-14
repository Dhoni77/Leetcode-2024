//
// Created by Aldrin on 13-03-2024.
//

#include "BestTimeToBuyAndSellStockIV.h"

int main() {
    BestTimeToBuyAndSellStockIV bestTimeToBuyAndSellStockIv;
    int k = 2;
    vector<int> prices{3,2,6,5,0,3};

    cout << bestTimeToBuyAndSellStockIv.maxProfit(k, prices);
}