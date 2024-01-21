//
// Created by Aldrin on 20-01-2024.
//

#ifndef DOOCS_SUBSETS_H
#define DOOCS_SUBSETS_H

#include "bits/stdc++.h"

using namespace std;

class Subsets {
public:
    // Iterative
    // Time complexity : O(N*(2^N))
    // Space complexity : O(N*(2^N))
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> subs = {{}};
        for (int num: nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        return subs;
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Bit Manipulation
     *     vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
     */
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * // Bit Manipulation
        // Time complexity : O(N*(2^N))
        // Space complexity : O(N*(2^N))
        class Solution {
        public:
            vector<vector<int>> subsets(vector<int>& nums) {
                int n = s.length();
                vector<string>ans;
                for (int num = 0; num < (1 << n); num++) {
                    string sub = "";
                    for (int i = 0; i < n; i++) {
                        //check if the ith bit is set or not
                        if (num & (1 << i)) {
                            sub += s[i];
                        }
                    }
                    if (sub.length() > 0) {
                        ans.push_back(sub);
                    }
                }
                sort(ans.begin(), ans.end());
                return ans;
            }
     */
};


#endif //DOOCS_SUBSETS_H
