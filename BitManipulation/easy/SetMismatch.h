//
// Created by Aldrin on 22-01-2024.
//

#ifndef DOOCS_SETMISMATCH_H
#define DOOCS_SETMISMATCH_H
#include "bits/stdc++.h"
using namespace std;

class SetMismatch {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), duplicate = 0, sumWithDuplicate = 0, originalSum = (n * (n + 1))/2;
        for(int i=0;i<n;i++) {
            int positive = abs(nums[i]);
            sumWithDuplicate += positive;
            nums[positive - 1] *= -1;
            if(nums[positive - 1] > 0)
                duplicate = positive;
        }
        return {duplicate, originalSum - (sumWithDuplicate - duplicate)};
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /**
     * Bit Manipulation
     * https://leetcode.com/problems/set-mismatch/solutions/2735371/c-solution-using-bit-manipulation-with-explaination/?envType=daily-question&envId=2024-01-22
     * **/
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     * TC: O(N)
     * SC: O(N)
     *
     *     vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = n * (n + 1) / 2;
        int array_sum = 0;
        int unique_sum = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for (int a : nums) {
            array_sum += a;
        }


        for (int a : s) {
            unique_sum += a;
        }

        int missing = actual_sum - unique_sum;
        int duplicate = array_sum - unique_sum;

        return {duplicate, missing};
    }
     */
    //----------------------------------------------------------------------------------------------------------------------------------
    /*
     *class Solution {
    public:
      vector<int> findErrorNums(vector<int>& nums) {
        int duplicate;

        for (const int num : nums)
          if (nums[abs(num) - 1] < 0)
            duplicate = abs(num);
          else
            nums[abs(num) - 1] *= -1;

        for (int i = 0; i < nums.size(); ++i)
          if (nums[i] > 0)
            return {duplicate, i + 1};

        throw;
      }
};
     */
    //--------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
        public:
            vector<int> findErrorNums(vector<int>& nums) {
                vector<int> H(1e4+1, 0);
                H[0] = 1;
                for (auto &v: nums) {
                    H[v]++;
                }
                int d = max_element(H.begin(), H.end()) - H.begin();
                int m = min_element(H.begin()+1, H.end()) - H.begin();
                return {d, m};
            }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------
    /*
     * Cycle Sort
     *
     * class Solution {
            public:
                vector<int> findErrorNums(vector<int>& nums) {
                    int missing=-1,extra=-1;
                    for(int i=0; i< nums.size() ; i++){
                        int idx = abs(nums[i])-1;

                        if(nums[idx]<0){
                            extra = abs(nums[i]);
                        }
                        else{
                            nums[idx]= -nums[idx];
                        }
                    }
                    for(int i=0; i< nums.size() ; i++){
                            if(nums[i]>0){
                                missing =i+1;
                                break;
                            }
                    }
                    return {extra,missing};
                }
            };
     */
};


#endif //DOOCS_SETMISMATCH_H
