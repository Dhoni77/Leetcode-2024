//
// Created by Aldrin on 27-03-2024.
//

#include "SubArrayProductLessThanK.h"

int main() {
    SubArrayProductLessThanK subArrayProductLessThanK;
//    vector<int> nums{10, 5, 2, 6};
    vector<int> nums{1,2,3,4,5};
    int k = 1;
    cout << subArrayProductLessThanK.numSubarrayProductLessThanK(nums, k);
}