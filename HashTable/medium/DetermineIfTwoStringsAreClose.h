//
// Created by Aldrin on 14-01-2024.
//

#ifndef DOOCS_DETERMINEIFTWOSTRINGSARECLOSE_H
#define DOOCS_DETERMINEIFTWOSTRINGSARECLOSE_H
#include "bits/stdc++.h"
using namespace std;

class DetermineIfTwoStringsAreClose {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        vector<int> w1mp(26, 0);
        vector<int> w2mp(26, 0);
        for(int i = 0; i < word1.size();i++) {
            w1mp[word1[i] - 'a']++;
            w2mp[word2[i] - 'a']++;
        }

        for(int i = 0; i < w1mp.size(); i++) {
            if((w1mp[i] == 0 and w2mp[i] > 0) or (w2mp[i] == 0 and w1mp[i] > 0))
                return false;
        }

        sort(w1mp.begin(), w1mp.end());
        sort(w2mp.begin(), w2mp.end());

        return (w1mp == w2mp);
    }
    // using bit manipulation
    /**
     *
     * class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> word1Map(26, 0);
        vector<int> word2Map(26, 0);
        int word1Bit = 0;
        int word2Bit = 0;
        for (auto c : word1) {
            word1Map[c - 'a']++;
            word1Bit = word1Bit | (1 << (c - 'a'));
        }
        for (auto c : word2) {
            word2Map[c - 'a']++;
            word2Bit = word2Bit | (1 << (c - 'a'));
        }
        if (word1Bit != word2Bit) return false;

        sort(word1Map.begin(), word1Map.end());
        sort(word2Map.begin(), word2Map.end());

        for (int i = 0; i < 26; i++) {
            if (word1Map[i] != word2Map[i]) return false;
        }
        return true;
    }
};
     * **/
};


#endif //DOOCS_DETERMINEIFTWOSTRINGSARECLOSE_H
