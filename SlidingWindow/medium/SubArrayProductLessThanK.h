//
// Created by Aldrin on 27-03-2024.
//

#ifndef DOOCS_SUBARRAYPRODUCTLESSTHANK_H
#define DOOCS_SUBARRAYPRODUCTLESSTHANK_H
#include "bits/stdc++.h"
using namespace std;

class SubArrayProductLessThanK {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), prod = 1, ans = 0;
        while (j < n) {
            prod *= nums[j];
            while(prod >= k and i <= j) {
                prod /= nums[i++];
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     * Binary Search Approach
     *
     * class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        double logK = log(k);
        int m = nums.size() + 1;
        vector<double> logsPrefixSum(m);

        // Calculate prefix sum of logarithms of elements
        for (int i = 0; i < nums.size(); i++) {
            logsPrefixSum[i + 1] = logsPrefixSum[i] + log(nums[i]);
        }

        int totalCount = 0;
        // Calculate subarray count with product less than k
        for (int currIdx = 0; currIdx < m; currIdx++) {
            int low = currIdx + 1, high = m;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (logsPrefixSum[mid] < logsPrefixSum[currIdx] + logK - 1e-9) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            totalCount += low - currIdx - 1;
        }
        return totalCount;
    }
};
     */
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    // Handle edge cases where k is 0 or 1 (no subarrays possible)
    if (k <= 1) return 0;

    int totalCount = 0;
    int product = 1;

    // Use two pointers to maintain a sliding window
    for (int left = 0, right = 0; right < nums.size(); right++) {
      // Expand the window by including the element at the right pointer
      product *= nums[right];

      // Shrink the window from the left while the product is greater than or equal to k
      while (product >= k) {
        // Remove the element at the left pointer from the product
        product /= nums[left++];
      }

      // Update the total count by adding the number of valid subarrays with the current window size
      totalCount += right - left + 1;  // right - left + 1 represents the current window size
    }

    return totalCount;
  }
};
     */
};


#endif //DOOCS_SUBARRAYPRODUCTLESSTHANK_H
