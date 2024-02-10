//
// Created by Aldrin on 09-02-2024.
//

#ifndef DOOCS_LARGESTDIVISIBLESUBSET_H
#define DOOCS_LARGESTDIVISIBLESUBSET_H
#include "bits/stdc++.h"
using namespace std;

class LargestDivisibleSubset {
public:
    vector<int> ans;
    void solve(int idx, int prev, int n, vector<int>& temp, vector<int> nums) {
        if(idx == n) {
            if(temp.size() > ans.size())
                ans = temp;
            return;
        }

        if(nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            solve(idx + 1, nums[idx], n, temp, nums);
            temp.pop_back();
        }
        solve(idx + 1, prev, n, temp, nums);
    }

    vector<int> largestDivisibleSubse(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, 1, nums.size(), temp, nums);
        return ans;
    }
    //-------------------------------------------------------------------------------------------------------------------
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), prevIndex(n, -1);
        int maxLen = 0, index = -1;
        // we sort to have the elements in increasing order thus avoding the need of nums[j] % nums[i]
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] % nums[j] == 0 and 1 + lis[j] > lis[i]) {
                    lis[i] = 1 + lis[j];
                    prevIndex[i] = j;
                }
            }

            if(lis[i] > maxLen) {
                maxLen = lis[i];
                index = i;
            }
        }

        vector<int> ans;
        while(index != -1) {
            ans.push_back(nums[index]);
            index = prevIndex[index];
        }

        return ans;
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Bottom up
     *
     * class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n , 1) , hash(n);
        int maxi = 1;
        int lastindex = 0;

        // sort the array
        sort(nums.begin() , nums.end());

        for(int ind = 0 ; ind < n ; ind++ ){

            hash[ind] = ind;

            for(int prev = 0 ; prev < ind ; prev++){

                if(nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind]){

                    dp[ind] = 1 +  dp[prev];
                    hash[ind] = prev; // update prev element index in hash

                }
            }

            if(maxi < dp[ind]){
                maxi = dp[ind];
                lastindex = ind;
            }

        }

        vector<int>temp;
        temp.push_back(nums[lastindex]);

        while(hash[lastindex] != lastindex){

            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);

        }

        reverse(temp.begin() , temp.end());

        return temp;
    }
};
     */
};


#endif //DOOCS_LARGESTDIVISIBLESUBSET_H
