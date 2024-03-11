//
// Created by Aldrin on 10-03-2024.
//

#ifndef DOOCS_INTERSECTIONOFTWOARRAYS_H
#define DOOCS_INTERSECTIONOFTWOARRAYS_H
#include "bits/stdc++.h"
using namespace std;

class IntersectionOfTwoArrays {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();
        set<int> st;
        while(i < n1 and j < n2) {
            if(nums1[i] < nums2[j])
                nums1[i++];
            else if(nums1[i] > nums2[j])
                nums2[j--];
            else {
                st.insert(nums1[i]);
                i++;
                j++;
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {


        unordered_set<int> hash1(nums1.begin(), nums1.end());
        unordered_set<int> hash2(nums2.begin(), nums2.end());

        vector<int> resultVec;

        if(hash1.size()>=hash2.size()){
            for(const auto &element:hash2){
                if(hash1.find(element) != hash1.end()){
                    resultVec.push_back(element);
                }
            }
        }
        else if(hash1.size()<hash2.size()){
            for(const auto& element:hash1){
                if(hash2.find(element) != hash2.end()){
                    resultVec.push_back(element);
                }
            }
        }

        return resultVec;

        }
    };
     */
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> ans;
    for (int num : set1) {
        if (set2.count(num)) {
            ans.push_back(num);
        }
    }

    return ans;
    }
};
     */
};


#endif //DOOCS_INTERSECTIONOFTWOARRAYS_H
