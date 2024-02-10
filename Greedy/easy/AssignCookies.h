//
// Created by Aldrin on 08-02-2024.
//

#ifndef DOOCS_ASSIGNCOOKIES_H
#define DOOCS_ASSIGNCOOKIES_H
#include "bits/stdc++.h"
using namespace std;

class AssignCookies {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gs = g.size(), ss = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while(i < gs and j < ss) {
            if(s[j] >= g[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
};


#endif //DOOCS_ASSIGNCOOKIES_H
