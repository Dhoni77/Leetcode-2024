//
// Created by Aldrin on 15-01-2024.
//

#include "FindWinners.h"

int main() {
    FindWinners fw;
//    vector<vector<int>> arr{
//            {1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}
//    };
    vector<vector<int>> arr{
            {2,3},{1,3},{5,4},{6,4}
    };
    fw.findWinners(arr);
}