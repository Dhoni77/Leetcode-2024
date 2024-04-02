//
// Created by Aldrin on 29-03-2024.
//

#ifndef DOOCS_COUNTSUBARRAYSWHEREMAXELEMENTAPPEARSATLEASTKTIMES_H
#define DOOCS_COUNTSUBARRAYSWHEREMAXELEMENTAPPEARSATLEASTKTIMES_H
#include "bits/stdc++.h"
using namespace std;

class CountSubArraysWhereMaxElementAppearsAtLeastKTimes {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        long long ans = 0, start = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == maxElement) {
                k--;
            }
            while (!k) {
                if (nums[start] == maxElement) {
                    k++;
                }
                start++;
            }
            ans += start;
        }
        return ans;
    }
    /*
     *     long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        unordered_map<long long, long long> mp;
        long long int ans = 0, maxi = *max_element(nums.begin(), nums.end());
        while(j < n) {
            mp[nums[j]]++;
            while(i <= j and mp[maxi] >= k) {
                ans += (n - j);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
    long long countSubarrays(vector<int>& A, int k) {
        int a = *max_element(A.begin(), A.end()), n = A.size(), cur = 0, i = 0;
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            cur += A[j] == a;
            while (cur >= k)
                cur -= A[i++] == a;
            res += i;
        }
        return res;
    }
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> indexesOfMaxElements;
        long long ans  = 0;

        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == maxElement) {
                indexesOfMaxElements.push_back(index);
            }

            int freq = indexesOfMaxElements.size();
            if (freq >= k) {
                ans += indexesOfMaxElements[freq - k] + 1;
            }
        }

        return ans;
    }
};
     */
};


#endif //DOOCS_COUNTSUBARRAYSWHEREMAXELEMENTAPPEARSATLEASTKTIMES_H
