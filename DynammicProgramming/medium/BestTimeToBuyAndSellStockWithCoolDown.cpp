//
// Created by Aldrin on 13-03-2024.
//

#include "BestTimeToBuyAndSellStockWithCoolDown.h"

int main() {
    BestTimeToBuyAndSellStockWithCoolDown bestTimeToBuyAndSellStockWithCoolDown;

    vector<int> prices{1,2,3,0,2};

    cout << bestTimeToBuyAndSellStockWithCoolDown.maxProfit(prices);
}