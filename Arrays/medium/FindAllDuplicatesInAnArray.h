//
// Created by Aldrin on 25-03-2024.
//

#ifndef DOOCS_FINDALLDUPLICATESINANARRAY_H
#define DOOCS_FINDALLDUPLICATESINANARRAY_H
#include "bits/stdc++.h"
using namespace std;

class FindAllDuplicatesInAnArray {
public:
    // https://leetcode.com/problems/find-all-duplicates-in-an-array/solutions/4921192/easy-solution-time-o-n-space-o-1-c-java-python3-kotlin/?envType=daily-question&envId=2024-03-25
    /*
     * vector<int> findDuplicates(vector<int>& nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        std::bitset<100001> cache;

        std::vector<int> result;
        for (const int& n : nums) {
            bool duplicate = cache.test(n);

            if (duplicate) {
                result.push_back(n);
            }
            else {
                cache.set(n);
            }
        }

        return result;
    }
     */
    //--------------------------------------------------------------------------------------------------------------------------
    vector<int> indexSolution(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            // mark as visited
            nums[index] *= -1;
            // incase of duplicate, this will become +ve
            if(nums[index] > 0)
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};


#endif //DOOCS_FINDALLDUPLICATESINANARRAY_H
