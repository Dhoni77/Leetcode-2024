//
// Created by Aldrin on 03-01-2024.
//

#ifndef DOOCS_NUMBEROFLASERBEAMSINBANK_H
#define DOOCS_NUMBEROFLASERBEAMSINBANK_H
#include "bits/stdc++.h"
using namespace std;

class NumberOfLaserBeamsInBank {
public:
    // TC: O(M*N)
    // SC: O(1)
    int numberOfBeams(vector<string>& bank) {
        if(bank.size() < 2)
            return 0;

        int result = 0;
        int prev = 0;
        for(auto b:bank) {
            int curr = 0;
            for(auto ch: b)
                curr += (ch - '0');
            if(curr) {
                result += curr * prev;
                prev = curr;
            }
        }
        return result;
    }
};


#endif //DOOCS_NUMBEROFLASERBEAMSINBANK_H
