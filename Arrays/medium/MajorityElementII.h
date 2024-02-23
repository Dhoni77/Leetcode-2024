//
// Created by Aldrin on 21-02-2024.
//

#ifndef DOOCS_MAJORITYELEMENTII_H
#define DOOCS_MAJORITYELEMENTII_H
#include "bits/stdc++.h"
using namespace std;

class MajorityElementII {
public:
        vector<int> majorityElement(vector<int>& nums) {
            int n1 = 0, n2 = 0;
            int m1 = 0, m2 = 1;
            for (int m : nums) {
                if (m == m1)
                    ++n1;
                else if (m == m2)
                    ++n2;
                else if (n1 == 0) {
                    m1 = m;
                    ++n1;
                } else if (n2 == 0) {
                    m2 = m;
                    ++n2;
                } else {
                    --n1;
                    --n2;
                }
            }
            vector<int> ans;
            if (count(nums.begin(), nums.end(), m1) > nums.size() / 3) ans.push_back(m1);
            if (count(nums.begin(), nums.end(), m2) > nums.size() / 3) ans.push_back(m2);
            return ans;
        }
};


#endif //DOOCS_MAJORITYELEMENTII_H
