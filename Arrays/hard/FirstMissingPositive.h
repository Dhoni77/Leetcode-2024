//
// Created by Aldrin on 26-03-2024.
//

#ifndef DOOCS_FIRSTMISSINGPOSITIVE_H
#define DOOCS_FIRSTMISSINGPOSITIVE_H
#include "bits/stdc++.h"
using namespace std;

class FirstMissingPositive {
public:
    // Similar to find the duplicate number
    // TC: O(n)
    // SC: O(1)
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;

        // if num < 0 set it to n + 1
        for(int i=0;i<n;i++)
            nums[i] = nums[i] <= 0 ? ans : nums[i];

        for(int i=0;i<n;i++) {
            int index = abs(nums[i]) - 1;
            // nums[index] > 0 is to check the duplicate case [1,1] and not to visit the same node again
            // index < n is to stay within the bounds
            if(index < n and nums[index] > 0)
                nums[index] *= -1;
        }

        for(int i=0;i<n;i++)
            if(nums[i] > 0)
                return i+1;

        return ans;
    }
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
     */
};


#endif //DOOCS_FIRSTMISSINGPOSITIVE_H
