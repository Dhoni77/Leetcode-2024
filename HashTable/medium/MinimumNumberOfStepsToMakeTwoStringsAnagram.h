//
// Created by Aldrin on 13-01-2024.
//

#ifndef DOOCS_MINIMUMNUMBEROFSTEPSTOMAKETWOSTRINGSPALINDROME_H
#define DOOCS_MINIMUMNUMBEROFSTEPSTOMAKETWOSTRINGSPALINDROME_H
#include "bits/stdc++.h"
using namespace std;

class MinimumNumberOfStepsToMakeTwoStringsPalindrome {
public:
    /*
     * To find this, we can record the frequency of each character in both strings s and t, and calculate the frequency difference
     * of each character (freq in t - freq in s). One important thing to note is that this difference can be positive or negative,
     * for example, if s = bba and t = baa, the frequency difference of a is 1 (t has 2 occurrences of a while s has 1, 2 - 1 = 1)
     * and the frequency difference of b is -1 (t has 1 occurrence of b while s has 2, 1 - 2 = -1). However, we only need to focus
     * on the positive value which implies that there are more instances of this character in t, why?

        This is because the two values (the sum of the positive and negative differences) are equal in absolute value! The positive
        value comes from the character in t that needs to be replaced, the negative value comes from the character in s that waits
        for the corresponding replacement in t.
     */
        int minSteps(string s, string t) {
            int count[26] = {0};
            // Storing the difference of frequencies of characters in t and s.
            for (int i = 0; i < s.size(); i++) {
                count[t[i] - 'a']++;
                count[s[i] - 'a']--;
            }

            int ans = 0;
            // Adding the difference where string t has more instances than s.
            // Ignoring where t has fewer instances as they are redundant and
            // can be covered by the first case.
            for (int i = 0; i < 26; i++) {
                ans += max(0, count[i]);
            }

            return ans;
        }
    //---------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *     int minSteps(string s, string t) {
        int occ[26] = {0};
        for (auto it : s) occ[it-'a'] ++;
        for (auto it : t) occ[it-'a']--;

        int res = 0;
        for (int i = 0; i < 26; i++) res += abs(occ[i]);

        return res / 2;
    }
     */
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
