//
// Created by Aldrin on 03-01-2024.
//

#ifndef DOOCS_MAXIMUMSUBARRAY_H
#define DOOCS_MAXIMUMSUBARRAY_H
#include "bits/stdc++.h"
using namespace std;

class MaximumSubArray {
public:
    /**
     * Sum of arr[i…j]=Sum of arr[i…j−1]+arr[j]
     * sum of elements from index i to j-1, it means the sum includes the elements from index i up to the element just before index j (j-1),
     * essentially covering the range [i...j-1], which is the subarray excluding the element at index j.
     * **/
//    /[-2,1,-3,4,-1,2,1,-5,4]
    int maxSubArray(vector<int>& nums) {
        long long maxi = INT_MIN;
        long long sum = 0;
        for(auto n: nums) {
            sum += n;
            if(sum > maxi) maxi = sum;
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    /**
     *int maxSubArray(vector<int> nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];

        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
            currentSubarray = max(num, currentSubarray + num);
            maxSubarray = max(maxSubarray, currentSubarray);
        }

        return maxSubarray;
    }
     * **/
    //-----------------------------------------------------------------------------------------------------------------------------
    /**
     * class Solution {
    public:
	int maxSubArray(vector<int>& nums){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            // sum --> Max. subarray sum ending at index i
            sum = max(nums[i], sum + nums[i]);

            // ans --> Max. subarray sum
            ans = max(ans, sum);
        }

        return ans;
    }
};
     * **/
};


#endif //DOOCS_MAXIMUMSUBARRAY_H
