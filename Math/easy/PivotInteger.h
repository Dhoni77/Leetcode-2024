//
// Created by Aldrin on 13-03-2024.
//

#ifndef DOOCS_PIVOTINTEGER_H
#define DOOCS_PIVOTINTEGER_H
#include "bits/stdc++.h"
using namespace std;

class PivotInteger {
public:
    // Two pointer approach
    /*
     * TC: O(N)
     * SC: O(1)
     */
    int pivotInteger(int n) {
        int lval = 1, rval = n, lsum = 1, rsum = n;

        if(n == 1)
            return 1;

        while(lval < rval) {
            if(lsum < rsum) {
                lval++;
                lsum += lval;
            }
            else {
                rval--;
                rsum += rval;
            }

            if(lsum == rsum and lval + 1 == rval - 1)
                return lval + 1;
        }

        return -1;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
         public:
          int pivotInteger(int n) {
                const int sum = (n * (n + 1) / 2);
                const int pivot = sqrt(sum);
                // If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
                return pivot * pivot == sum ? pivot : -1;
          }
        };
     */
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int pivotInteger(int n) {
        // Initialize left and right pointers for binary search
        int left = 1, right = n;

        // Calculate the total sum of the sequence
        int totalSum = n * (n + 1) / 2;

        // Binary search for the pivot point
        while (left < right) {
            // Calculate the mid-point
            int mid = (left + right) / 2;

            // Check if the difference between the square of mid and the total sum is negative
            if (mid * mid - totalSum < 0) {
                left = mid + 1; // Adjust the left bound if the sum is smaller
            } else {
                right = mid; // Adjust the right bound if the sum is equal or greater
            }
        }

        // Check if the square of the left pointer minus the total sum is zero
        if (left * left - totalSum == 0) {
            return left;
        } else {
            return -1;
        }
    }
};
     */
};


#endif //DOOCS_PIVOTINTEGER_H
