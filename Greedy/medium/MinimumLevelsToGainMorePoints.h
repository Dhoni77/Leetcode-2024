//
// Created by Aldrin on 01-04-2024.
//

#ifndef DOOCS_MINIMUMLEVELSTOGAINMOREPOINTS_H
#define DOOCS_MINIMUMLEVELSTOGAINMOREPOINTS_H
#include "bits/stdc++.h"
using namespace std;

class MinimumLevelsToGainMorePoints {
public:
    int minimumLevels(vector<int>& possible) {
        int total = 0, daniel = 0;

        for(int t: possible)
            total += (t ? t : -1);

        for(int i=0;i<possible.size()-1;i++) {
            daniel += (possible[i] ? 1 : -1);
            int bob = total - daniel;
            if(daniel > bob) {
                return i+1;
            }
        }
        return -1;
    }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int s = 0;
        for (int x : possible) {
            s += x == 0 ? -1 : 1;
        }
        int t = 0;
        for (int i = 1; i < possible.size(); ++i) {
            t += possible[i - 1] == 0 ? -1 : 1;
            if (t > s - t) {
                return i;
            }
        }
        return -1;
    }
};
     */
};


#endif //DOOCS_MINIMUMLEVELSTOGAINMOREPOINTS_H
