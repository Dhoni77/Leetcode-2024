//
// Created by Aldrin on 22-02-2024.
//

#ifndef DOOCS_FOURSUM_H
#define DOOCS_FOURSUM_H
#include "bits/stdc++.h"
using namespace std;

class FourSum {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> res;

        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        long long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if  (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = int(nums.size()) - 1;

        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }

        return res;
    }
    /*
     * vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++) {
            if(i != 0 and nums[i] == nums[i-1])
                continue;
            for(int j=i+1;j<n;j++) {
                if(j != 1 and nums[j] == nums[j-1])
                    continue;
                int k = j + 1, l = n - 1;
                while(k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum > target) {
                        l--;
                    }
                    else if(sum < target) {
                        k++;
                    }
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                        while(k < l and nums[k] == nums[k-1])
                            k++;
                        while(k < l and nums[l] == nums[l+1])
                            l--;
                    }
                }
            }
        }
        return res;
    }
     */
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     * KSum Official
     *
     * class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> res;

        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        long long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if  (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = int(nums.size()) - 1;

        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }

        return res;
    }
};
     */
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * KSum official hash map
     *
     * class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> res;

        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        long long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if  (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& subset : kSum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        unordered_set<long long> s;

        for (int i = start; i < nums.size(); ++i) {
            if (res.empty() || res.back()[1] != nums[i]) {
                if (s.count(target - nums[i])) {
                    res.push_back({int(target - nums[i]), nums[i]});
                }
            }
            s.insert(nums[i]);
        }

        return res;
    }
};
     */
};


#endif //DOOCS_FOURSUM_H
