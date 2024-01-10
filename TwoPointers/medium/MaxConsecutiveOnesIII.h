//
// Created by Aldrin on 10-01-2024.
//

#ifndef DOOCS_MAXCONSECUTIVEONESIII_H
#define DOOCS_MAXCONSECUTIVEONESIII_H
#include "bits/stdc++.h"
using namespace  std;

class MaxConsecutiveOnesIII {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, count = 0, j = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] == 0)
                count++;
            while(count > k)
            {
                if(nums[j++] == 0) {
                    count--;
                }
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};


#endif //DOOCS_MAXCONSECUTIVEONESIII_H
