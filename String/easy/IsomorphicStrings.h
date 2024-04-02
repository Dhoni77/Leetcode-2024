//
// Created by Aldrin on 02-04-2024.
//

#ifndef DOOCS_ISOMORPHICSTRINGS_H
#define DOOCS_ISOMORPHICSTRINGS_H
#include "bits/stdc++.h"
using namespace std;

class IsomorphicStrings {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, bool> used;
        for(int i=0;i<s.size();i++) {
            if(mp.count(s[i])) {
                if(mp[s[i]] != t[i])
                    return false;
            }
            else {
                if(used.count(t[i]))
                    return false;
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0},m2[256] = {0},n = s.size();
        for(int i = 0; i < n;i++)
        {
            if(m1[s[i]] != m2[t[i]])
            {
                return false;
            }
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
     */
};


#endif //DOOCS_ISOMORPHICSTRINGS_H
