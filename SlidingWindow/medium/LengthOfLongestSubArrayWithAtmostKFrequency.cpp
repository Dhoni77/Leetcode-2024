//
// Created by Aldrin on 28-03-2024.
//

#include "LengthOfLongestSubArrayWithAtmostKFrequency.h"

int main() {
    LengthOfLongestSubArrayWithAtmostKFrequency lengthOfLongestSubArrayWithAtmostKFrequency;

    vector<int> nums{5,5,5,5,5,5,5};
    int k = 4;

    cout << lengthOfLongestSubArrayWithAtmostKFrequency.maxSubarrayLength(nums, k);
}