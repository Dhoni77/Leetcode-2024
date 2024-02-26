//
// Created by Aldrin on 26-02-2024.
//

#ifndef DOOCS_MAXIMUMPRODUCTSUBARRAY_H
#define DOOCS_MAXIMUMPRODUCTSUBARRAY_H
#include "bits/stdc++.h"
using namespace std;

class MaximumProductSubArray {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN, p = 1;
        for(int n: nums) {
            p *= n;
            maxi = max(maxi, p);
            if(n == 0)
                p = 1;
        }
        p = 1;
        for(int i=nums.size() - 1;i>=0;i--) {
            p *= nums[i];
            maxi = max(maxi, p);
            if(nums[i] == 0)
                p = 1;
        }
        return maxi;
    }
    /*
     *
     * Intuition:
The problem requires finding the maximum product of a subarray within the given array. To approach this, the code calculates the maximum product from both the prefix and suffix of the array. This approach ensures that both positive and negative values are considered to find the maximum product.

Approach:

Initialize variables prefix and suffix to 1. These variables will keep track of the product of elements in the prefix and suffix subarrays.
Note: Now what is prefix and suffix here?
Prefix is all the subarrays from the start of the array and Suffix is all the subarrays from the back.
E.g.: [2,-4,5,0,4,3]
prefix is [2],[2,-4],[2,-4,5]...[2,-4,5,0,4,3]
suffix is [3], [4,3], [0,4,3]...[2,-4,5,0,4,3]

Initialize variables maxPref and maxSuff to INT_MIN. These variables will store the maximum product seen in the prefix and suffix subarrays.

Like in the above example, prefix is initially 2 so maxPref is 2, then 2*-4=-8, but max of -8 and 2 is 2 so maxPref is still 2.
Special case: when zero comes between subarrays
Assume 0 to be a seperator between the subarrays because if you multiple zero with the ongoing prefix or suffix products, it'll make them zero which we do not want, so we do not consider to multiply zero in our traversal. To do this, we check that if the element is zero and is multiplied to make prefix/suffix zero, we reset it to 1 for a fair multiplication of upcoming elements.

So, after 2*-4=-8, maxPref is still 2. Now comes 0 which makes prefix to -8*0=0 but we do not want to carry this zero forward for upcoming multiplications because this will make everything zero. Rather we ignore it, by resetting prefix/suffix to 1, so that a new subarray product can begin after 0.
so assume that 0 seperated the array in two parts:
[2,-4,5] and [4,3]
We, find the MAX product for both the parts,in form of maxPref and maxSuff.

More details about other step

Iterate through the nums array using a loop:
Update prefix by multiplying it with the current element nums[i].
Update maxPref by taking the maximum of the current maxPref and prefix.
Update suffix by multiplying it with the current element nums[n-1-i], where n is the size of the array.
Update maxSuff by taking the maximum of the current maxSuff and suffix.
After the loop, return the maximum of maxPref and maxSuff as it represents the maximum product of a subarray within the array.
Complexity:

Time complexity: The code iterates through the array once, making it a linear-time algorithm with a time complexity of O(n), where n is the number of elements in the nums array.
Space complexity: The code uses a constant amount of extra space for variables, regardless of the size of the input array. Therefore, the space complexity is O(1).
Here's the code with the details filled in:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int maxPref = INT_MIN;
        int maxSuff = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }

            prefix *= nums[i];
            maxPref = max(maxPref, prefix);
            suffix *= nums[n - 1 - i];
            maxSuff = max(maxSuff, suffix);
        }

        return max(maxSuff, maxPref);
    }
};
     */
};


#endif //DOOCS_MAXIMUMPRODUCTSUBARRAY_H
