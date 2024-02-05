//
// Created by Aldrin on 02-02-2024.
//

#ifndef DOOCS_NEXTGREATERELEMENTI_H
#define DOOCS_NEXTGREATERELEMENTI_H
#include "bits/stdc++.h"
using namespace std;

class NextGreaterElementI {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i: nums2) {
            while(!st.empty() and st.top() < i) {
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(int i: nums1) {
            ans.push_back(mp[i] ? mp[i] : -1);
        }

        return ans;
    }
    //---------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
 public:
      vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> numToNextGreater;
        stack<int> stack;  // a decreasing stack

        for (const int num : nums2) {
          while (!stack.empty() && stack.top() < num)
            numToNextGreater[stack.top()] = num, stack.pop();
          stack.push(num);
        }

        for (const int num : nums1)
          if (const auto it = numToNextGreater.find(num);
              it != numToNextGreater.cend())
            ans.push_back(it->second);
          else
            ans.push_back(-1);

        return ans;
      }
};
     */
};


#endif //DOOCS_NEXTGREATERELEMENTI_H
