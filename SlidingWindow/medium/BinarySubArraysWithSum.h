//
// Created by Aldrin on 16-01-2024.
//

#ifndef DOOCS_BINARYSUBARRAYSWITHSUM_H
#define DOOCS_BINARYSUBARRAYSWITHSUM_H
#include "bits/stdc++.h"
using namespace std;

class BinarySubArraysWithSum {
public:
    /**
     *int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefixSum = 0, count = 0;
        // store the count of each unique prefix sum
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int num: nums) {
            prefixSum += num;
            // check for sub arrays with desired sum
            if(auto it = mp.find(prefixSum - goal);it != mp.end()) {
                count += it->second;
            }
            // update count of current prefix sum in map
            mp[prefixSum]++;
        }
        return count;
    }
     * **/
    //------------------------------------------------------------------------------------------------------------------------------------------------------
    /**
     *  int helper(vector<int>& nums, int goal){
        int n = nums.size(), count = 0, i = 0, j = 0, sum = 0;
        while(j < n){
            sum += nums[j];
            while(i <= j && sum > goal)
                sum -= nums[i++];
            count += j - i + 1;
            j++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = helper(nums,goal);
        int m = helper(nums,goal - 1);
        return n - m;
    }
     * **/
    //----------------------------------------------------------------------------------------------------------------------------------------------------------
     int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> cnt(n + 1);
        cnt[0] = 1;
        int ans = 0, sum = 0;
        for (int& v : nums) {
            sum += v;
            if (sum - goal >= 0) {
                ans += cnt[sum - goal];
            }
            cnt[sum]++;
        }
        return ans;
    }
};


#endif //DOOCS_BINARYSUBARRAYSWITHSUM_H
