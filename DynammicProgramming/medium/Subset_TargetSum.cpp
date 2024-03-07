//
// Created by Aldrin on 07-03-2024.
//

#include "Subset_TargetSum.h"

int main() {
    Subset_TargetSum subsetTargetSum;

    vector<int> nums{1, 1, 1, 1, 1};

    int target = 3;

    cout << subsetTargetSum.findTargetSumWays(nums, target);
}