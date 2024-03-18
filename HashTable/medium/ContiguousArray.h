//
// Created by Aldrin on 16-03-2024.
//

#ifndef DOOCS_CONTIGUOUSARRAY_H
#define DOOCS_CONTIGUOUSARRAY_H
#include "bits/stdc++.h"
using namespace std;

class ContiguousArray {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxLen = 0, count = 0;
        for(int i=0;i<nums.size();i++) {

            count += (count == 0 ? -1 : 1);

            if(mp.find(count) == mp.end()) {
                mp[count] = i;
                if(count == 0) {
                    maxLen = max(maxLen, i + 1);
                }
            } else if(count == 0) {
                maxLen = max(maxLen, i + 1);
            }
            else {
                maxLen = max(maxLen, i - mp[count]);
            }
        }

        return maxLen;
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxLen = 0, count = 0;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++) {
            count += (nums[i] == 1 ? 1 : -1);

            if(mp.find(count) != mp.end()) {
                maxLen = max(maxLen, i - mp[count]);
            }
            else {
                mp[count] = i;
            }
        }

        return maxLen;
    }
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int>arr(2*n+1,INT_MIN);
        arr[n]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)sum--;
            else sum++;
            if(arr[sum+n]>=-1){
                ans=max(ans,i-arr[sum+n]);
            }
            else{
                arr[sum+n]=i;
            }

        }
        return ans;
    }
};
     */
};


#endif //DOOCS_CONTIGUOUSARRAY_H
