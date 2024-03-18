//
// Created by Aldrin on 15-03-2024.
//

#ifndef DOOCS_PRODUCTOFARRAYEXCEPTSELF_H
#define DOOCS_PRODUCTOFARRAYEXCEPTSELF_H
#include "bits/stdc++.h"
using namespace std;

class ProductOfArrayExceptSelf {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, postfix = 1, n = nums.size();
        vector<int> result(n, 1);
        for(int i=0;i<nums.size();i++) {
            result[i] *= prefix;
            prefix *= nums[i];
        }

        for(int i=n-1;i>=0;i--) {
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int n=nums.size();
        output.push_back(1);
        for(int i=1;i<=n;i++){
            output.push_back(output[i-1]*nums[i-1]);
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            output[i]*=right;
            right*=nums[i];
        }
        output.pop_back();
        return output;
    }
};
     */
    //------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), result(n, 1);
        for(int i=1;i<n;i++) {
            prefix[i] = nums[i-1] * prefix[i - 1];
        }

        for(int i=n-2;i>=0;i--) {
            suffix[i] = nums[i+1] * suffix[i+1];
        }

        for(int i=0;i<n;i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
     */
};


#endif //DOOCS_PRODUCTOFARRAYEXCEPTSELF_H
