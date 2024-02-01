//
// Created by Aldrin on 01-02-2024.
//

#include "DivideArrayIntoArraysWithMaxDifference.h"

int main() {
    DivideArrayIntoArraysWithMaxDifference divideArrayIntoArraysWithMaxDifference;
//    vector<int> nums{1,3,4,8,7,9,3,5,1};
    vector<int> nums{15,13,12,13,12,14,12,2,3,13,12,14,14,13,5,12,12,2,13,2,2};
    int k = 2;
    divideArrayIntoArraysWithMaxDifference.divideArray(nums, k);
}