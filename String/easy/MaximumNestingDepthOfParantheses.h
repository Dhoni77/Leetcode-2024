//
// Created by Aldrin on 04-04-2024.
//

#ifndef DOOCS_MAXIMUMNESTINGDEPTHOFPARANTHESES_H
#define DOOCS_MAXIMUMNESTINGDEPTHOFPARANTHESES_H
#include "bits/stdc++.h"
using namespace std;

class MaximumNestingDepthOfParantheses {
public:
    int maxDepth(string s) {
        int open = 0, ans = 0;
        for(auto ch: s) {
            if(ch == '(')
                ans = max(ans, ++open);
            if(ch == ')')
                open--;
        }
        return ans;
    }
};


#endif //DOOCS_MAXIMUMNESTINGDEPTHOFPARANTHESES_H
