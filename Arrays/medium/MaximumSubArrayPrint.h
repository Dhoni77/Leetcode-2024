//
// Created by Aldrin on 03-01-2024.
//

#ifndef DOOCS_MAXIMUMSUBARRAYPRINT_H
#define DOOCS_MAXIMUMSUBARRAYPRINT_H
#include "bits/stdc++.h"
using namespace std;

class MaximumSubArrayPrint {
public:
    /**
     * int maxSubArray(vector<int>& nums) {
        int start = 0;
        int end = 0;
        long long maxi = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            int sum = 0;
            for(int j=i;j<nums.size();j++) {
                sum += nums[j];
                if(sum > maxi) {
                    maxi = sum;
                    start = i;
                    end = j;
                }
            }
        }
        for(int i=start;i <= end;i++) {
            cout << nums[i] << endl;
        }
    }
     * **/

    int maxSubArray(vector<int>& nums) {
        long long maxi = INT_MIN;
        long long sum = 0;
        int start = 0;
        int end = 0;
        for(int i=0;i<nums.size();i++) {
            if(sum == 0) {
                start = i;
            }
            sum += nums[i];
            if(sum > maxi) {
                maxi = sum;
                end = i;
            }
            if(sum < 0) {
                sum = 0;
            }
        }
        for(int i=start;i<=end;i++) {
            cout << nums[i] << endl;
        }
    }
};


#endif //DOOCS_MAXIMUMSUBARRAYPRINT_H
