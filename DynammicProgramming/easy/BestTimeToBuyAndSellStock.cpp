//
// Created by Aldrin on 03-01-2024.
//

#include "BestTimeToBuyAndSellStock.h"

int main() {
    BestTimeToBuyAndSellStock bt;
    vector<int> prices {7, 6, 4, 3, 1};
//    vector<int> prices {7, 1, 5, 3, 6, 4};
    cout << bt.maxProfit(prices);
}