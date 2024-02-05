//
// Created by Aldrin on 02-02-2024.
//

#ifndef DOOCS_NEXTGREATERELEMENTII_H
#define DOOCS_NEXTGREATERELEMENTII_H
#include "bits/stdc++.h"
using namespace std;

class NextGreaterElementII {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);

        for(int i=2 * n - 1;i >= 0;i--) {
            while(!st.empty() and st.top() <= nums[i % n])
                st.pop();
            if(i < n and !st.empty())
                nge[i] = st.top();
            st.push(nums[i % n]);
        }
        return nge;
    }
};


#endif //DOOCS_NEXTGREATERELEMENTII_H
