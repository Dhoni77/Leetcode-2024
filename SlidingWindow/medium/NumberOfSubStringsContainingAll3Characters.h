//
// Created by Aldrin on 16-01-2024.
//

#ifndef DOOCS_NUMBEROFSUBSTRINGSCONTAININGALL3CHARACTERS_H
#define DOOCS_NUMBEROFSUBSTRINGSCONTAININGALL3CHARACTERS_H
#include "bits/stdc++.h"
using  namespace std;

class NumberOfSubStringsContainingAll3Characters {
public:
    int numberOfSubstrings(string s) {
        vector<int> mp(3, -1);
        int ans = 0;
        for(int i = 0;i<s.size();i++) {
            mp[s[i] - 'a'] = i;
            ans += min({mp[0], mp[1], mp[2]}) + 1;
        }
        return ans;
    }
};


#endif //DOOCS_NUMBEROFSUBSTRINGSCONTAININGALL3CHARACTERS_H
