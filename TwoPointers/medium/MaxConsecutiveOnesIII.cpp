//
// Created by Aldrin on 10-01-2024.
//

#include "MaxConsecutiveOnesIII.h"

int main() {
    MaxConsecutiveOnesIII mc;
    vector<int> nums{1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << mc.longestOnes(nums, k);
}