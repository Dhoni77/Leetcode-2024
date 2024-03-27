//
// Created by Aldrin on 27-03-2024.
//

#include "SubArraysWithKDifferentIntegers.h"

int main() {
    SubArraysWithKDifferentIntegers subArraysWithKDifferentIntegers;

    vector<int> nums{1,2,1,2,3};
    int k = 2;

    cout << subArraysWithKDifferentIntegers.subarraysWithKDistinct(nums, k);
}