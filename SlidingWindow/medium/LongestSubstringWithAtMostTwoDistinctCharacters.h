//
// Created by Aldrin on 27-03-2024.
//

#ifndef DOOCS_LONGESTSUBSTRINGWITHATMOSTTWODISTINCTCHARACTERS_H
#define DOOCS_LONGESTSUBSTRINGWITHATMOSTTWODISTINCTCHARACTERS_H
#include "bits/stdc++.h"
using namespace std;

class LongestSubstringWithAtMostTwoDistinctCharacters {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char, int> mp;
        for(int i=0, j=0;i<n;i++) {
            mp[s[i]]++;
            while(mp.size() > 2) {
                mp[s[j]]--;
                if(mp[s[j]] == 0) {
                    mp.erase(s[j]);
                }
                j++;
            }
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};


#endif //DOOCS_LONGESTSUBSTRINGWITHATMOSTTWODISTINCTCHARACTERS_H
