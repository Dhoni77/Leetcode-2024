//
// Created by Aldrin on 17-01-2024.
//

#ifndef DOOCS_UNIQUENUMBEROFOCCURENCES_H
#define DOOCS_UNIQUENUMBEROFOCCURENCES_H
#include "bits/stdc++.h"
using namespace std;

class UniqueNumberOfOccurences {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(int n: arr) {
            mp[n]++;
        }
        for(auto m: mp) {
            if(st.find(m.second) != st.end()) {
                return false;
            }
            else {
                st.insert(m.second);
            }
        }
        return true;
    }
};


#endif //DOOCS_UNIQUENUMBEROFOCCURENCES_H
