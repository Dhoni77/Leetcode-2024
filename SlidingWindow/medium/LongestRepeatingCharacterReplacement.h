//
// Created by Aldrin on 15-01-2024.
//

#ifndef DOOCS_LONGESTREPEATINGCHARACTERREPLACEMENT_H
#define DOOCS_LONGESTREPEATINGCHARACTERREPLACEMENT_H
#include "bits/stdc++.h"
using namespace std;

class LongestRepeatingCharacterReplacement {
public:
    int characterReplacement(string s, int k) {
        vector<int> alpha(26, 0);
        int ans = 0, maxCount = INT_MIN;
        for(int r=0, l = 0;r<s.size();r++) {
            maxCount = max(maxCount, ++alpha[s[r] - 'A']);
            while(r - l + 1 > maxCount + k) {
                --alpha[s[l++] - 'A'];
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};


#endif //DOOCS_LONGESTREPEATINGCHARACTERREPLACEMENT_H
