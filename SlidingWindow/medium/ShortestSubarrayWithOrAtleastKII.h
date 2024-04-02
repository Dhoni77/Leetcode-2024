//
// Created by Aldrin on 01-04-2024.
//

#ifndef DOOCS_SHORTESTSUBARRAYWITHORATLEASTKII_H
#define DOOCS_SHORTESTSUBARRAYWITHORATLEASTKII_H
#include "bits/stdc++.h"
using namespace std;

class ShortestSubarrayWithOrAtleastKII {
public:
    void addContributionToBitSet(int val, vector<int> &bs, bool isAdd) {
        int i = 0;
        while(val > 0) {
            bs[i] = bs[i] + (isAdd ? 1 : -1) * val % 2;
            val /= 2;
            i++;
        }
    }

    bool isContributionGreaterThanK(vector<int> bs, int k) {
        int res = 0;
        for(int i=0;i<32;i++) {
            res += (bs[i] ? 1 : 0) * pow(2, i);
        }
        return res >= k;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitset(32, 0);
        int n = nums.size(), i = 0, j = 0, ans = INT_MAX;
        while(j < n) {
            addContributionToBitSet(nums[j], bitset, true);
            while(i<=j and isContributionGreaterThanK(bitset, k)) {
                ans = min(ans, j - i + 1);
                // remove contribution
                addContributionToBitSet(nums[i], bitset, false);
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt[32]{};
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
        }
        return ans > n ? -1 : ans;
    }
};
     */
};


#endif //DOOCS_SHORTESTSUBARRAYWITHORATLEASTKII_H
