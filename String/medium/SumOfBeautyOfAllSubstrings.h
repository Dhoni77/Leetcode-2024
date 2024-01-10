//
// Created by Aldrin on 10-01-2024.
//

#ifndef DOOCS_SUMOFBEAUTYOFALLSUBSTRINGS_H
#define DOOCS_SUMOFBEAUTYOFALLSUBSTRINGS_H
#include "bits/stdc++.h"
using namespace std;

class SumOfBeautyOfAllSubstrings {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            vector<int> freq(26, 0);
            for(int j=i;j<n;j++) {
                int maxi = INT_MIN, mini = INT_MAX;
                freq[s[j] - 'a']++;
                for(int f: freq) {
                    if(f > 0) {
                        maxi = max(maxi, f);
                        mini = min(mini, f);
                    }
                }
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};


#endif //DOOCS_SUMOFBEAUTYOFALLSUBSTRINGS_H
