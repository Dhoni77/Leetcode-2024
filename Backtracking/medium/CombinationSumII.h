//
// Created by Aldrin on 26-01-2024.
//

#ifndef DOOCS_COMBINATIONSUMII_H
#define DOOCS_COMBINATIONSUMII_H
#include "bits/stdc++.h"
using namespace std;

class CombinationSumII {
public:
    // TC: O(n * 2 ^ n)
    // SC: O(n + n * 2 ^ n) = O(n * 2 ^ n)
    vector<vector<int>> ans;
    void solve(int idx, int n, int target, vector<int> nums, vector<int>& result) {
        if(target == 0) {
            ans.push_back(result);
            return;
        }
        for(int i=idx;i<n;i++) {
            if(i > idx and nums[i] == nums[i-1])
                continue;
            if(nums[i] > target)
                break;
            result.push_back(nums[i]);
            solve(i + 1, n, target - nums[i], nums, result);
            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates.size(), target, candidates, result);
        return ans;
    }
};


#endif //DOOCS_COMBINATIONSUMII_H
