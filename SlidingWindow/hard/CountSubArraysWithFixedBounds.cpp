//
// Created by Aldrin on 31-03-2024.
//

#include "CountSubArraysWithFixedBounds.h"

int main() {
    CountSubArraysWithFixedBounds countSubArraysWithFixedBounds;
    vector<int> nums{1, 3, 5, 2, 7, 5};
    int mink = 1, maxk = 5;
    cout << countSubArraysWithFixedBounds.countSubarrays(nums, mink, maxk);
}