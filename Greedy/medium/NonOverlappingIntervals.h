//
// Created by Aldrin on 21-02-2024.
//

#ifndef DOOCS_NONOVERLAPPINGINTERVALS_H
#define DOOCS_NONOVERLAPPINGINTERVALS_H
#include "bits/stdc++.h"
using namespace std;

class NonOverlappingIntervals {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b) {
            return a[1] < b[1];
        });
        int n = intervals.size(), count = 0, t = intervals[0][1];

        for(int i=1;i<n;i++) {
            if(t <= intervals[i][0]) {
                t = intervals[i][1];
            }
            else
                ++count;
        }

        return count;
    }
};


#endif //DOOCS_NONOVERLAPPINGINTERVALS_H
