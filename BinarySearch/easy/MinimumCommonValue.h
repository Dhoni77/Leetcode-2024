//
// Created by Aldrin on 09-03-2024.
//

#ifndef GEEKSFORGEEKS_MINIMUMCOMMONVALUE_H
#define GEEKSFORGEEKS_MINIMUMCOMMONVALUE_H
#include "bits/stdc++.h"
using namespace std;

class MinimumCommonValue {
public:
    /*
     * TC: O(n+m)
     * SC: O(1)
     */
        int getCommon(vector<int>& nums1, vector<int>& nums2) {
            int first = 0;
            int second = 0;

            // Traverse through both arrays with two pointers
            // Increment the pointer with a smaller value at that index
            // Return the first common element found
            while (first < nums1.size() && second < nums2.size()) {
                if (nums1[first] < nums2[second]) {
                    first++;
                } else if (nums1[first] > nums2[second]) {
                    second++;
                } else {
                    return nums1[first];
                }
            }

            // Return -1 if there are no common elements
            return -1;
        }
        //-------------------------------------------------------------------------------------------------------------------------
        /*
         * Binary Search
         *
         * mid, the middle of the subarray, is set to the index in the middle of the array. The basic midpoint formula is (left + right) / 2.
            You'll notice that the below implementations instead use left + (right - left) / 2. This is because if left + right is greater than the maximum integer value, 2^31-1
            , it overflows and causes errors.
            left + (right - left) / 2 is an equivalent formula, and never stores a value larger than left or right. Thus, if left and right are within the integer limits, we will never overflow.
         *
         * TC: O(N log M)
         * SC: O(1)
         *
         * class Solution {
            public:
                int getCommon(vector<int>& nums1, vector<int>& nums2) {
                    // Binary search should be done on the larger array
                    // If nums1 is longer, call getCommon with the arrays swapped
                    if (nums1.size() > nums2.size()) {
                        return getCommon(nums2, nums1);
                    }

                    // Search for each element of nums1 in nums2
                    // Return the first common element found
                    for (int num : nums1) {
                        if (binarySearch(num, nums2)) {
                            return num;
                        }
                    }

                    // Return -1 if there are no common elements
                    return -1;
                }

            private:
                bool binarySearch(int target, vector<int>& nums) {
                    int left = 0;
                    int right = nums.size() - 1;
                    while (left <= right) {
                        int mid = left + (right - left) / 2;
                        if (nums[mid] > target) {
                            right = mid - 1;
                        } else if (nums[mid] < target) {
                            left = mid + 1;
                        } else {
                            return true;
                        }
                    }
                    return false;
                }
            };
         */
};


#endif //GEEKSFORGEEKS_MINIMUMCOMMONVALUE_H
