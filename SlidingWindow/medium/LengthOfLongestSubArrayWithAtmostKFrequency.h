//
// Created by Aldrin on 28-03-2024.
//

#ifndef DOOCS_LENGTHOFLONGESTSUBARRAYWITHATMOSTKFREQUENCY_H
#define DOOCS_LENGTHOFLONGESTSUBARRAYWITHATMOSTKFREQUENCY_H
#include "bits/stdc++.h"
using namespace std;

class LengthOfLongestSubArrayWithAtmostKFrequency {
public:
    int atmostK(vector<int> nums, int k) {
        int i = 0, j = 0, n = nums.size(), ans = 0;
        unordered_map<int, int> mp;

        while(j < n) {
            mp[nums[j]]++;
            // shrink
            while(i <= j and mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }

    int maxSubarrayLength(vector<int>& nums, int k) {
        return atmostK(nums, k);
    }

    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * TC: O(N)
     * SC: O(N)
     *
     * class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, start = -1;
        unordered_map<int, int> frequency;

        for (int end = 0; end < nums.size(); end++) {
            frequency[nums[end]]++;
            while (frequency[nums[end]] > k) {
                start++;
                frequency[nums[start]]--;
            }
            ans = max(ans, end - start);
        }

        return ans;
    }
};
     */
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> frequency;
        int start = 0;
        int charsWithFreqOverK = 0;

        for (int end = 0; end < n; end++) {
            frequency[nums[end]]++;
            if (frequency[nums[end]] == k + 1) {
                charsWithFreqOverK++;
            }
            if (charsWithFreqOverK > 0) {
                frequency[nums[start]]--;
                if (frequency[nums[start]] == k) {
                    charsWithFreqOverK--;
                }
                start++;
            }
        }
        return n - start;
    }
};
     */
};


#endif //DOOCS_LENGTHOFLONGESTSUBARRAYWITHATMOSTKFREQUENCY_H
