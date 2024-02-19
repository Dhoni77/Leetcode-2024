//
// Created by Aldrin on 15-02-2024.
//

#ifndef DOOCS_FINDPOLYGONWITHTHELARGESTPERIMETER_H
#define DOOCS_FINDPOLYGONWITHTHELARGESTPERIMETER_H
#include "bits/stdc++.h"
using namespace std;

class FindPolygonWithTheLargestPerimeter {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long maxi = INT_MIN;
        sort(nums.begin(), nums.end());
        long long prefix = nums[0] + nums[1];
        for(int i=2;i<nums.size();i++) {
            if(prefix > nums[i]) {
                maxi = max(maxi, prefix + nums[i]);
            }
            prefix = prefix + nums[i];
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};


#endif //DOOCS_FINDPOLYGONWITHTHELARGESTPERIMETER_H
