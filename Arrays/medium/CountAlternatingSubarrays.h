//
// Created by Aldrin on 01-04-2024.
//

#ifndef DOOCS_COUNTALTERNATINGSUBARRAYS_H
#define DOOCS_COUNTALTERNATINGSUBARRAYS_H
#include "bits/stdc++.h"
using namespace std;

class CountAlternatingSubarrays {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long int ans = 0;
        int latestOccurence = -1;
        for(int i=0;i<nums.size();i++) {
            if(i > 0 and nums[i] == nums[i-1]) {
                latestOccurence = i - 1;
            }
            ans += (i - latestOccurence);
        }
        return ans;
    }
    //------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 1, s = 1;
        for (int i = 1; i < nums.size(); ++i) {
            s = nums[i] != nums[i - 1] ? s + 1 : 1;
            ans += s;
        }
        return ans;
    }
};
     */
};


#endif //DOOCS_COUNTALTERNATINGSUBARRAYS_H
