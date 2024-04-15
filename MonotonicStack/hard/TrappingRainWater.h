//
// Created by Aldrin on 12-04-2024.
//

#ifndef DOOCS_TRAPPINGRAINWATER_H
#define DOOCS_TRAPPINGRAINWATER_H
#include "bits/stdc++.h"
using namespace std;

class TrappingRainWater {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);

        left[0] = height[0];
        for(int i=1;i<n;i++) {
            left[i] = max(height[i-1], left[i]);
        }

        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--) {
            right[i] = max(height[i+1], right[i]);
        }

        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += (min(left[i], right[i]) - height[i]);
        }

        return ans;
    }
};


#endif //DOOCS_TRAPPINGRAINWATER_H
