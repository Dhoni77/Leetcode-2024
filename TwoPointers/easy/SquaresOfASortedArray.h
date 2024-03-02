//
// Created by Aldrin on 02-03-2024.
//

#ifndef DOOCS_SQUARESOFASORTEDARRAY_H
#define DOOCS_SQUARESOFASORTEDARRAY_H
#include "bits/stdc++.h"
using namespace std;

class SquaresOfASortedArray {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> ans;
        while(i < n) {
            if(nums[i] < 0)
                i++;
            else break;
        }
        // beginning of j from 1 to n
        j = i;
        // beginning of i from 1 to n
        i = i - 1;
        while(i > -1 and j < n) {
            if((-1 * nums[i]) > nums[j]) {
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
            else {
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
        }

        // remaining
        while(i > -1) {
            ans.push_back(nums[i] * nums[i]);
            i--;
        }

        while(j < n) {
            ans.push_back(nums[j] * nums[j]);
            j++;
        }

        return ans;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Two pointers
     *
     * class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> sorted(n);

        for (int i=n-1; i>=0; i--) {
            if (abs(nums[left]) >= abs(nums[right])) {
                sorted[i] = pow(nums[left], 2);
                left++;
            }
            else {
                sorted[i] = pow(nums[right], 2);
                right--;
            }
        }

        return sorted;
    }
};
     */
};


#endif //DOOCS_SQUARESOFASORTEDARRAY_H
