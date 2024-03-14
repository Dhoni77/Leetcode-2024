//
// Created by Aldrin on 13-03-2024.
//

#include "BestTimeToBuyAndSellStockWithTransactionFee.h"

int main() {
    BestTimeToBuyAndSellStockWithTransactionFee bestTimeToBuyAndSellStockWithTransactionFee;
    int fee = 2;
    vector<int> prices{1,3,2,8,4,9};

    cout << bestTimeToBuyAndSellStockWithTransactionFee.maxProfit(prices, fee);
}