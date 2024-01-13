//
// Created by Aldrin on 13-01-2024.
//

#ifndef DOOCS_MINIMUMNUMBEROFSTEPSTOMAKETWOSTRINGSPALINDROME_H
#define DOOCS_MINIMUMNUMBEROFSTEPSTOMAKETWOSTRINGSPALINDROME_H
#include "bits/stdc++.h"
using namespace std;

class MinimumNumberOfStepsToMakeTwoStringsPalindrome {
public:
    int minSteps(string s, string t) {
        int occ[26] = {0};
        for (auto it : s) occ[it-'a'] ++;
        for (auto it : t) occ[it-'a']--;

        int res = 0;
        for (int i = 0; i < 26; i++) res += abs(occ[i]);

        return res / 2;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------
    /**
     * int minSteps(string s, string t) {
        unordered_map<char, int> ss;
        unordered_map<char, int> tt;
        int ans = 0;
        for(int i=0;i<s.size();i++) {
            ss[s[i]]++;
            tt[t[i]]++;
        }

        for(auto smap: ss) {
            int tfreq = tt[smap.first];
            if(smap.second > tfreq) {
                ans += (smap.second - tfreq);
            }
        }
        return ans;
    }
     * **/
};


#endif //DOOCS_MINIMUMNUMBEROFSTEPSTOMAKETWOSTRINGSPALINDROME_H
