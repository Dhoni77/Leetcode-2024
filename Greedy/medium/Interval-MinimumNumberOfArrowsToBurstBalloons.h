//
// Created by Aldrin on 18-03-2024.
//

#ifndef DOOCS_INTERVAL_MINIMUMNUMBEROFARROWSTOBURSTBALLOONS_H
#define DOOCS_INTERVAL_MINIMUMNUMBEROFARROWSTOBURSTBALLOONS_H
#include "bits/stdc++.h"
using namespace std;

class Interval {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows = 1;
        sort(points.begin(), points.end());
        int end = points[0][1];
        for(int i=1;i<points.size();i++) {
            if(points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
            else end = min(end, points[i][1]);
        }
        return arrows;
    }
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        long long last = -(1LL << 60);
        for (auto& p : points) {
            int a = p[0], b = p[1];
            if (a > last) {
                ++ans;
                last = b;
            }
        }
        return ans;
    }
};
     */
};


#endif //DOOCS_INTERVAL_MINIMUMNUMBEROFARROWSTOBURSTBALLOONS_H
