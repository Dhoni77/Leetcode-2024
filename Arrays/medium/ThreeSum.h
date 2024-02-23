//
// Created by Aldrin on 22-02-2024.
//

#ifndef DOOCS_THREESUM_H
#define DOOCS_THREESUM_H
#include "bits/stdc++.h"
using namespace std;

class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++) {
            if(i != 0 and nums[i] == nums[i-1])
                continue;
            int j = i + 1, k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) {
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while(j < k and nums[j] == nums[j-1])
                        j++;
                    while(j < k and nums[k] == nums[k+1])
                        k--;
                }
            }
        }
        return res;
    }
    //----------------------------------------------------------------------------------------------------------------------------
    /* Brute Force
     *
     *     vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j + 1;k<n;k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp{nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
     */
    //-----------------------------------------------------------------------------------------------------------------------------
    /*
     * Set
     *
     *     vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        for(int i=0;i<n;i++) {
            set<int> st;
            for(int j=i+1;j<n;j++) {
                int target = -(nums[i] + nums[j]);
                if(st.count(target)) {
                    vector<int> temp{nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                st.insert(nums[j]);
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
     */
};


#endif //DOOCS_THREESUM_H
