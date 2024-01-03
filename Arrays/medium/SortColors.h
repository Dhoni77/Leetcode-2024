//
// Created by Aldrin on 03-01-2024.
//

#ifndef DOOCS_MAXIMUMSUBARRAY_H
#define DOOCS_MAXIMUMSUBARRAY_H
#include "bits/stdc++.h"
using namespace std;

class MaximumSubArray {
public:
    void maxSubArray(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


#endif //DOOCS_MAXIMUMSUBARRAY_H
