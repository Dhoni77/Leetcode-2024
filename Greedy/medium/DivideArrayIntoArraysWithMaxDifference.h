//
// Created by Aldrin on 01-02-2024.
//

#ifndef DOOCS_DIVIDEARRAYINTOARRAYSWITHMAXDIFFERENCE_H
#define DOOCS_DIVIDEARRAYINTOARRAYSWITHMAXDIFFERENCE_H
#include "bits/stdc++.h"
using namespace std;

class DivideArrayIntoArraysWithMaxDifference {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(n % 3)
            return {};
        for(int i=0;i<n;i+=3) {
            vector<int> temp = {nums[i], nums[i+1], nums[i+2]};
            if(temp[2] - temp[0] <= k)
                ans.push_back(temp);
            else return {};
        }
        return ans;
    }
};


#endif //DOOCS_DIVIDEARRAYINTOARRAYSWITHMAXDIFFERENCE_H
