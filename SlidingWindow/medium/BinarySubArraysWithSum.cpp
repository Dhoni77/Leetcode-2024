//
// Created by Aldrin on 16-01-2024.
//

#include "BinarySubArraysWithSum.h"

int main() {
    BinarySubArraysWithSum bs;

    vector<int> nums {1, 0, 1, 0, 1};
    int goal = 2;

    cout << bs.numSubarraysWithSum(nums, goal);
}