//
// Created by Aldrin on 03-01-2024.
//

#ifndef DOOCS_TWOSUM_H
#define DOOCS_TWOSUM_H
#include "bits/stdc++.h"
using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++) {
            int need = target - nums[i];
            if(mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};


#endif //DOOCS_TWOSUM_H
