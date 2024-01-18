//
// Created by Aldrin on 16-01-2024.
//

#ifndef DOOCS_COUNTNUMBEROFNICESUBARRAYS_H
#define DOOCS_COUNTNUMBEROFNICESUBARRAYS_H
#include "bits/stdc++.h"
using namespace std;

class CountNumberOfNiceSubarrays {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prefixSum = 0, count = 0;
        // store the count of each unique prefix sum
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int num: nums) {
            prefixSum += (num % 2);
            // check for sub arrays with desired sum
            if(auto it = mp.find(prefixSum - k);it != mp.end()) {
                count += it->second;
            }
            // update count of current prefix sum in map
            mp[prefixSum]++;
        }
        return count;
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------
    /**
     * Efficient solution
     *
     *int numberOfSubarrays(vector<int>& nums, int k) {
        int prefixSum = 0, count = 0;
        // store the count of each unique prefix sum
        vector<int> mp(nums.size() + 1, 0);
        mp[0] = 1;
        for(int num: nums) {
            prefixSum += (num & 1);
            // check for sub arrays with desired sum
            if(prefixSum - k >= 0) {
                count += mp[prefixSum - k];
            }
            // update count of current prefix sum in map
            mp[prefixSum]++;
        }
        return count;
    }
     * **/
};


#endif //DOOCS_COUNTNUMBEROFNICESUBARRAYS_H
